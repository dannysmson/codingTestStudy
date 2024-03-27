#include <bits/stdc++.h>
using namespace std;

// 전보 (최단 거리 Dijkstra Alg.)
// 시간 제한: 1초, 메모리 제한: 128MB
// N개의 도시, X도시에서 Y도시로 메시지를 보내기 위해선 연결되어 있어야 함
// C라는 도시에서 위급 상황이 발생했을 때, 메시지를 받을 수 있는 도시의 갯수와 모두 받는 데까지 걸리는 시간
const int INF = 987654321;
int n, m, c, from, to, weight, dist[30001];
vector<pair<int,int>> adj[30001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void dijkstra(int start)
{
    dist[start] = 0;
    PQ.push(make_pair(0, start));
    while(PQ.size())
    {
        int here = PQ.top().second;
        int dist_here = PQ.top().first;
        PQ.pop();
        if(dist_here != dist[here]) continue;
        for(pair<int,int> there : adj[here])
        {
            int _there = there.second;
            int _d = there.first;
            if(dist_here + _d < dist[_there])
            {
                dist[_there] = dist_here + _d;
                PQ.push(make_pair(dist[_there], _there));
            }
        }
    }
}
int main()
{
    fastIO();
    int n, m, c;
    fill(dist, dist+30001, INF);
    cin >> n >> m >> c;
    if(n<1 || n>30000 || m<1 || m>200000 || c<1 || c>n) exit(0);
    for(int i=0; i<m; i++)
    {
        cin >> from >> to >> weight;
        adj[from].push_back(make_pair(weight, to));
    }
    dijkstra(c);
    int ret = 0, _d = 0;
    for(int i=2; i<=n; i++)
    {
        if(dist[i] != INF)
        {
            ret++;
            _d = max(_d, dist[i]);
        }
    }
    cout << ret << " " << _d << "\n";
    return 0;
}