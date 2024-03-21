#include <bits/stdc++.h>
using namespace std;

// 미로 탈출 (BFS Alg.)

// 시간 제한: 1초, 메모리 제한: 128MB
// NxM 크기의 직사각형 형태 미로
// 출발 위치 (1,1), 출구 위치 (N,M), 괴물이 있는 부분: 0, 괴물이 없는 부분: 1
// 탈출을 위해 움직여야 할 최소 칸의 갯수 구하기
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, arr[201][201], visited[201][201];
string str;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void bfs(int y, int x)
{
    queue<pair<int,int>> q;
    q.push(make_pair(y, x));
    visited[y][x] = 1;
    while(q.size())
    {
        tie(y, x) = q.front(); q.pop();
        for(int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(visited[ny][nx] || !arr[ny][nx]) continue;
            q.push(make_pair(ny, nx));
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
    return;
}
int main()
{
    fastIO();
    // 입력 부분
    cin >> n >> m;
    if(n < 4 || n > 200 || m < 4 || m > 200) exit(0); // 입출력 처리
    for(int i=0; i<n; i++)
    {
        cin >> str;
        for(int j=0; j<str.size(); j++)
        {
            arr[i][j] = (int)(str[j] - '0');
        }
    }
    bfs(0, 0);
    cout << visited[n-1][m-1] << "\n";
    return 0;
}