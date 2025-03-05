#include <bits/stdc++.h>
using namespace std;

// 녹색 옷 입은 애가 젤다지?
const int dy[] = {-1 , 0 , 1 , 0};
const int dx[] = {0, 1, 0, -1};
const int INF = 987654321;
int dist[126][126], cave[126][126];
int n;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void inputError()
{
    exit(0);
}
void bfs()
{
	queue <pair<int, int>> pq;
	pq.push(make_pair(0, 0));
	dist[0][0] = cave[0][0];
	while (!pq.empty()) 
    {
		int y = pq.front().first;
		int x = pq.front().second;
		pq.pop();
		for (int i = 0; i < 4; i++) 
        {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < n) 
            {
				if (dist[ny][nx] > dist[y][x] + cave[ny][nx]) 
                {
					dist[ny][nx] = dist[y][x] + cave[ny][nx];
					pq.push(make_pair(ny, nx));
				}
			}
		}
	}

}
void solution()
{
    int idx = 1;
    while(1)
    {
        cin >> n;
        if(n < 2 || n > 125) inputError();
        if(n == 0) return;
        fill(&dist[0][0], &dist[125][126], INF);
        memset(cave, 0, sizeof(cave));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> cave[i][j];
                if(cave[i][j] < 0 || cave[i][j] > 9) inputError();
            }
        }
        bfs();
        cout << "Problem " << idx << ": " << dist[n-1][n-1] << "\n";
        idx++;
    }
}
int main()
{
    fastIO();
    solution();
    return 0;
}