#include <bits/stdc++.h>
using namespace std;

// 음식물 피하기 (실버1. DFS Alg.)
// https://www.acmicpc.net/problem/1743
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, k, y, x, ret, sum, visited[101][101], arr[101][101];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void dfs(int y, int x)
{
    visited[y][x] = 1;
    sum++;
    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx] || !arr[ny][nx]) continue;
        dfs(ny, nx);
    }
    return;
}
int main()
{
    fastIO();
    cin >> n >> m >> k;
    if(n<1 || n>100 || m<1 || m>100 || k<1 || k>n*m) exit(0);

    for(int i=0; i<k; i++)
    {
        cin >> y >> x;
        arr[y-1][x-1] = 1;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!visited[i][j] && arr[i][j])
            {
                sum = 0;
                dfs(i, j);
                ret = max(ret, sum);
            }
        }
    }
    cout << ret << "\n";
    return 0;
}