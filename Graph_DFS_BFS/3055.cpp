#include <bits/stdc++.h>
using namespace std;

// 탈출 (BFS Alg.)
// https://www.acmicpc.net/problem/3055
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, flag, visited[51][51], ret=-1;
char arr[51][51];
vector<pair<int,int>> water;
pair<int,int> start;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void bfs()
{
    queue<pair<pair<int,int>, int>> que;
    que.push({{start.first, start.second}, 0});
    visited[start.first][start.second] = 1;
    for(pair<int,int> it : water)
    {
        que.push({{it.first, it.second}, -1});
    }
    while(que.size())
    {
        int y = que.front().first.first;
        int x = que.front().first.second;
        int cnt = que.front().second;
        que.pop();

        if(cnt != -1 && arr[y][x] == 'D')
        {
            ret = cnt;
            return;
        }

        for(int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(arr[ny][nx] == 'X' || arr[ny][nx] == '*') continue;
            if(arr[y][x] == '*')
            {
                if(arr[ny][nx] == 'D') continue;
                que.push({{ny,nx}, cnt});
                arr[ny][nx] = '*';
            } else {
                if(visited[ny][nx]) continue;
                que.push({{ny,nx}, cnt + 1});
                visited[ny][nx] = 1;
            }
        }
    }
    return;
}
int main()
{
    fastIO();
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == '*') water.push_back(make_pair(i,j));
            if(arr[i][j] == 'S') start = {i, j};
        }
    }
    bfs();
    if(ret == -1) cout << "KAKTUS" << "\n";
    else cout << ret << "\n";
    return 0;
}