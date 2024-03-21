#include <bits/stdc++.h>
using namespace std;

// 음료수 얼려 먹기 (DFS Alg.)

// 시간 제한: 1초, 메모리 제한: 128MB
// NxM 크기의 얼음 틀
// 구멍이 뚫린 부분: 0, 칸막이 존재 부분: 1
// 얼음 틀의 모양이 주어졌을 때 생성되는 총 아이스크림의 갯수 구하기
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, arr[1001][1001], visited[1001][1001], ret;
string str;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void dfs(int y, int x)
{
    visited[y][x] = 1;
    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(visited[ny][nx] || arr[ny][nx]) continue;
        dfs(ny, nx);
    }
    return;
}
int main()
{
    fastIO();
    // 입력 부분
    cin >> n >> m;
    if(n < 1 || n > 1000 || m < 1 || m > 1000) exit(0); // 입출력 처리
    for(int i=0; i<n; i++)
    {
        cin >> str;
        for(int j=0; j<str.size(); j++) arr[i][j] = (int)(str[j] - '0');
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!visited[i][j] && !arr[i][j]) // 구멍이 뚫려 있으며 아직 방문하지 않은 부분이면 방문
            {
                dfs(i, j);
                ret++;
            }
        }
    }
    cout << ret << "\n";
    return 0;
}