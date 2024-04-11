#include <bits/stdc++.h>
using namespace std;

// 삼성전자 코딩테스트 기출문제
// 로봇청소기(Dfs Alg.)
// https://www.acmicpc.net/problem/14503
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, dir, room[51][51], visited[51][51], ret, startY, startX;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void go(int y, int x, int dir)
{
    // 현재 칸 청소
    if(!visited[y][x])
    {
        visited[y][x] = 1;
        ret++;
    }

    // 주변 4칸 확인 (바라보는 방향에 왼쪽부터)
    for(int i=0; i<4; i++)
    {
        int ndir = (dir+3-i) % 4;
        int ny = y + dy[ndir];
        int nx = x + dx[ndir];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(visited[ny][nx] || room[ny][nx]) continue;
        // 주변 4칸에 청소되지 않은 빈칸이 있는 경우
        go(ny, nx, ndir);
    }
    // 주변 4칸에 청소되지 않은 빈칸이 없는 경우
    // 바라보는 방향 유지, 한 칸 뒤로 후진
    int ny = y + dy[(dir+2)%4];
    int nx = x + dx[(dir+2)%4];
    if(ny < 0 || ny >= n || nx < 0 || nx >= m || room[ny][nx])
    {
        cout << ret << "\n";
        exit(0);
    } else{
        go(ny,nx,dir);
    }
    return;
}
int main()
{
    fastIO();
    cin >> n >> m;
    if(n<3 || n>50 || m<3 || m>50) exit(0);
    cin >> startY >> startX >> dir;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> room[i][j];
        }
    }
    go(startY, startX, dir);
    return 0;
}