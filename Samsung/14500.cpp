#include <bits/stdc++.h>
using namespace std;

// 삼성전자 코딩테스트 기출문제
// 테트로미노 (DFS Alg.)
// https://www.acmicpc.net/problem/14500
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, arr[501][501], visited[501][501], ret;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void dfs(int y, int x, int depth, int sum)
{
    visited[y][x] = 1;
    sum += arr[y][x];
    if(depth == 4)
    {
        ret = max(ret, sum);
        visited[y][x] = 0;
        return;
    }
    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
        dfs(ny, nx, depth+1, sum);
    }
    visited[y][x] = 0;
    return;
}
void T(int y, int x)    // T자 모형은 dfs로 카운팅이 안되기 때문에
{
    int sum = 0;
    for(int i=0; i<4; i++)
    {
        sum = arr[y][x];
        for(int j=0; j<4; j++)
        {
            if(i == j) continue;
            int ny = y + dy[j];
            int nx = x + dx[j];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            sum += arr[ny][nx];
        }
        ret = max(ret, sum);
    }
    return;
}
int main()
{
    fastIO();
    cin >> n >> m;
    if(n<4 || n>500 || m<4 || m>500) exit(0);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            dfs(i, j, 1, 0);   // 'T' 모양을 제외한 나머지 테트로미노
            T(i, j);
        }
    }
    cout << ret << "\n";
    return 0;
}