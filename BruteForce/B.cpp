#include <bits/stdc++.h>
using namespace std;
// 게임 개발 (Brute Force Alg.)
// 시간 제한: 1초, 메모리 제한: 128MB
// N x M 크기의 직사각형, 캐릭터의 위치 (A,B)
// 반시계 방향으로 한 칸씩 이동하되 육지인 경우에만 이동가능
// 캐릭터가 방문한 칸의 수를 출력

int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int n, m, y, x, d, ret, arr[51][51], visited[51][51];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int turn_left(int d)
{
    d -= 1;
    if(d == -1) d = 3;
    return d;
}
void go(int y, int x, int d)
{
    int turn = 0;
    while(1)
    {
        d = turn_left(d);
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(arr[ny][nx] == 0 && visited[ny][nx] == 0)
        {
            visited[ny][nx] = 1;
            y = ny; x = nx;
            ret++;
            turn = 0;
            continue;
        } else
        {
            turn++;
        }
        if(turn == 4)
        {
            int ny = y - dy[d];
            int nx = x - dx[d];
            if(arr[ny][nx] == 0)
            {
                y = ny; x = nx;
            } else
            {
                break;
            }
            turn = 0;
        }
    }
    return;
}
int main()
{
    fastIO();
    cin >> n >> m;
    if(n < 3 || n > 50 || m < 3 || m > 50) exit(0);
    cin >> y >> x >> d;
    if(y < 0 || y > n || x < 0 || x > m || d < 0 || d > 3) exit(0);
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> arr[i][j];
        }
    }
    go(y, x, d);
    cout << ret << "\n";
    return 0;
}