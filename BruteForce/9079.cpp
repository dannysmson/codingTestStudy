#include <bits/stdc++.h>
using namespace std;

// 동전 게임 (실버 2 - Brute Force Alg.)
// https://www.acmicpc.net/problem/9079
int testCase, arr[3][3];
bool visited[512];
char ch;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int arrayToInt()
{
    int ret = 0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            ret = ret * 2 + arr[i][j];
        }
    }
    return ret;
}
void intToArray(int num)
{
    for(int i=2; i>=0; i--)
    {
        for(int j=2; j>=0; j--)
        {
            arr[i][j] = num % 2;
            num /= 2;
        }
    }
    return;
}
int bfs()
{
    queue<pair<int,int>> que;
    int start = arrayToInt();
    que.push({start, 0});
    visited[start] = true;

    while(!que.empty())
    {
        int cur = que.front().first;
        int cnt = que.front().second;
        que.pop();

        // 모든 숫자가 0이거나 1이면 = 모든 숫자가 같은 숫자면
        if(cur == 0 || cur == 511) return cnt;
        intToArray(cur);

        // 열 변환
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                arr[j][i] ^= 1;
            }
            int next = arrayToInt();
            if(!visited[next])
            {
                visited[next] = true;
                que.push({next, cnt + 1});
            }
            for(int j=0; j<3; j++)
            {
                arr[j][i] ^= 1;
            }
        }
        
        // 행 변환
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                arr[i][j] ^= 1;
            }
            int next = arrayToInt();
            if(!visited[next])
            {
                visited[next] = true;
                que.push({next, cnt + 1});
            }
            for(int j=0; j<3; j++)
            {
                arr[i][j] ^= 1;
            }
        }

        // 대각선 변환
        for(int i=0; i<=1; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(i == 0) arr[j][j] ^= 1;
                else arr[j][2-j] ^= 1;
            }
            int next = arrayToInt();
            if(!visited[next])
            {
                visited[next] = true;
                que.push({next, cnt + 1});
            }
            for(int j=0; j<3; j++)
            {
                if(i == 0) arr[j][j] ^= 1;
                else arr[j][2-j] ^= 1;
            }
        }
    }
    return -1;
}
int main()
{
    fastIO();
    cin >> testCase;
    if(testCase < 1 || testCase > 10) exit(0);

    while(testCase--)
    {
        memset(visited, false, sizeof(visited));
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cin >> ch;
                if(ch == 'H') arr[i][j] = 1;
                else if(ch == 'T') arr[i][j] = 0;
                else exit(0);
            }
        }
        cout << bfs() << "\n";
    }
    return 0;
}