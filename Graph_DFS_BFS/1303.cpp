#include <bits/stdc++.h>
using namespace std;

// 전쟁 - 전투 (실버 1. DFS Alg.)
// https://www.acmicpc.net/problem/1303
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
char arr[101][101];
int n, m, visited[101][101], ret1, ret2, cnt;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int dfs(int y, int x, char ch)
{
    visited[y][x] = 1;
    cnt++;
    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
        if(visited[ny][nx] || arr[ny][nx] != ch) continue;
        dfs(ny, nx, ch);
    }
    return cnt;
}
int main()
{
    fastIO();
    cin >> m >> n;
    if(n<1 || n>100 || m<1 || m>100) exit(0);

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
            cnt = 0;
            if(!visited[i][j])
            {
                cnt = dfs(i, j, arr[i][j]);
                if(arr[i][j] == 'W') ret1 += (cnt * cnt);
                else if(arr[i][j] == 'B') ret2 += (cnt * cnt);
            }
        }
    }
    cout << ret1 << " " << ret2 << "\n";
    return 0;
}