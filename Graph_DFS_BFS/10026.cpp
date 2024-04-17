#include <bits/stdc++.h>
using namespace std;

// 적록색약 (골드 4 DFS Alg.)
// https://www.acmicpc.net/problem/10026
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, ret1, ret2, visited1[101][101], visited2[101][101];
char arr[101][101];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// 일반 사람이 확인하는 구역 갯수
void dfs1(int y, int x)
{
    visited1[y][x] = 1;
    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited1[ny][nx]) continue;
        if(arr[y][x] != arr[ny][nx]) continue;
        dfs1(ny, nx);
    }
    return;
}
// 적록색약 사람들이 확인하는 구역 갯수 (적색, 녹색 구별 못함)
void dfs2(int y, int x)
{
    visited2[y][x] = 1;
    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited2[ny][nx]) continue;
        if(((arr[y][x] == 'R') && (arr[ny][nx] == 'G')) || ((arr[y][x] == 'G') && (arr[ny][nx] == 'R'))) dfs2(ny,nx);
        if(arr[y][x] == arr[ny][nx]) dfs2(ny,nx);
    }
    return;
}
int main()
{
    fastIO();
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!visited1[i][j])
            {
                dfs1(i, j);
                ret1++;
            }
            if(!visited2[i][j])
            {
                dfs2(i,j);
                ret2++;
            }
        }
    }
    cout << ret1 << " " << ret2 << "\n";
    return 0;
}