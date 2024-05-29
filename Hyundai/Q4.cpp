#include <bits/stdc++.h>
using namespace std;

// 상 하 좌 우 1 2 4 8
const int dy[] = {-1, 0, 1, 0}; // 북 동 남 서
const int dx[] = {0, 1, 0, -1};
const int dir[] = {2, 4, 1, 8}; // 남 서 북 동
const int dir2[] = {1, 8, 2, 4};
int n, ret, block[51][51];
char arr[51][51];
bool flag = false;
queue<pair<pair<int,int>, char>> que;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
bool check(int y, int x, char ch)   // 아직 점령하지 않은 나라를 점령하려 할 때, 주변에 인접한 국가가 얼마나 있는지 확인하는 함수
{
    int c[26];
    memset(c, 0, sizeof(c));
    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(arr[ny][nx] == '0') continue;
        if(!(arr[ny][nx] >= 'A' && arr[ny][nx] <= 'Z')) continue;
        if(block[ny][nx] != 0 && (block[ny][nx] & dir2[i])) continue; // 장애물 체크
        c[(int)(arr[ny][nx] - 'A')]++;
    }
    int _max = c[ch-'A'];
    for(int i=0; i<26; i++)
    {
        if(i == ch-'A') continue;
        if(c[i] >= _max) return false;
    }
    return true;
}
void solution()
{
    while(1)
    {
        queue<pair<pair<int,int>, char>> tmp;
        vector<pair<pair<int,int>, char>> v;
        while(!que.empty())
        {
            ret++;
            int y = que.front().first.first;
            int x = que.front().first.second;
            char ch = que.front().second;
            que.pop();
            for(int i=0; i<4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;        // 범위 체크
                if(arr[ny][nx] >= 'A' && arr[ny][nx] <= 'Z') continue;      // 다른 국가가 점령한 땅인지 체크
                if(block[ny][nx] != 0 && (block[ny][nx] & dir[i])) continue;    // 장애물 체크
                if(check(ny, nx, ch))
                {
                    tmp.push({{ny,nx}, ch});
                    v.push_back({{ny,nx}, ch});
                }
            }
        }
        que = tmp;
        if(que.empty())break;
        for(auto it : v)
        {
            int y = it.first.first;
            int x = it.first.second;
            char ch = it.second;
            arr[y][x] = ch;
        }
    }
    cout << ret << "\n";
    return;
}
int main()
{
    fastIO();
    cin >> n;
    if(n<1 || n>50) exit(0);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] >= 'A' && arr[i][j] <= 'Z')
            {
                que.push({{i,j}, arr[i][j]});
            }
            if(arr[i][j] >= '1' && arr[i][j] <= '9') block[i][j] = arr[i][j] - '0';   // 점령해도 방벽은 사라지지 않기에 방벽 유지 
        }
    }
    cout << "\n";
    solution();
    return 0;
}
/*
5
A 0 0 0 0
0 0 6 0 D
0 0 B 0 0
0 C 8 0 0
0 0 0 0 0

3
A A A D D
A A D D D
0 0 B B D
C C C B D
C C C 0 D

-숫자로 표현된 구간은 테두리가 있는 공간
-테두리가 있는 공간은 나라가 점령 불가능
-인접한 국가의 갯수가 동일하면 그 점령지는 점령 불가
- 더이상 점령가능한 땅이 없을 때까지 진행하며 최종적인 턴 수와 땅의 형태 출력
- 장애물이 있는 땅을 국가가 점령하더라도 장애물은 사라지지 않음
*/