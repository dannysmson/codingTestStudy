#include <bits/stdc++.h>
using namespace std;

// 미래 도시 (최단거리 Floyd-Warshall Alg.)
// 시간 제한: 1초, 메모리 제한: 128MB
// 1번부터 N번까지의 회사, 특정 회사끼리는 도로를 통해 연결
// 방문 판매원 A는 1번회사에 위치, K번회사를 거쳐 X번회사를 방문해 물건을 판매하려 함
// 회사 사이의 최소 이동 시간을 계산
const int INF = 987654321;
int n, m, K, X, from, to, dist[101][101];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int main()
{
    fastIO();
    fill(&dist[0][0], &dist[0][0] + 101 * 101, INF);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> from >> to;
        dist[from-1][to-1] = 1;
        dist[to-1][from-1] = 1;
    }
    cin >> X >> K;
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    if(dist[0][K-1] == INF || dist[K-1][X-1] == INF) cout << -1 << "\n";
    else cout << dist[0][K-1] + dist[K-1][X-1] << "\n";
}