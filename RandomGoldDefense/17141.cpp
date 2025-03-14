#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

// 17141 연구소 2
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const int INF = 987654321;
int arr[54][54], visited[54][54];
int n, m, ret = INF;
vector<pair<int, int>> virus;
vector<pair<int, int>> virus_comb;

void bfs()
{
    queue<pair<int, int>> que;
    int cnt = 0;
    for(int i=0; i<virus_comb.size(); i++) 
    {
        que.push(virus_comb[i]);
        visited[virus_comb[i].first][virus_comb[i].second] = 1;
    }
    while(!que.empty())
    {
        cnt++;
        int _size = que.size();
        for(int j=0; j<_size; j++)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();
            for(int i=0; i<4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= n || arr[ny][nx] == 1 || visited[ny][nx]) continue;
                visited[ny][nx] = visited[y][x] + 1;
                que.push({ny, nx});
            }
        }
    }
    bool check = true;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j] != 1 && !visited[i][j])
            {
                check = false;
                break;
            }
        }
    }
    if(check) ret = min(ret, cnt-1);
    return;
}
// 바이러스 조합 구하기
void solution(int idx)
{
    if(virus_comb.size() == m)
    {
        memset(visited, 0, sizeof(visited));
        bfs();
        return;
    }
    for(int i=idx+1; i<virus.size(); i++)
    {
        virus_comb.push_back(virus[i]);
        solution(i);
        virus_comb.pop_back();
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 2) virus.push_back({i, j});
        }
    }
    solution(-1);
    if(ret == INF) ret = -1;
    cout << ret << "\n";
    return 0;
}