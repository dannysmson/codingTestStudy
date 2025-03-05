#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

// 도로검문

const int INF = 1e9;
int n, m, vA, vB, t;
vector<pair<int,int>> adj[1004];
vector<int> dist(1004, INF);
vector<int> parent[1004];
vector<pair<int,int>> shortest_edges;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> vA >> vB >> t;
        adj[vA].push_back({t, vB});
        adj[vB].push_back({t, vA});
    }
    return;
}
void dijkstra(int start)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;
    fill(dist.begin(), dist.end(), INF);
    for (int i = 0; i <= n; i++) parent[i].clear(); // 부모 정보 초기화
    dist[start] = 0;
    PQ.push({0, start});
    while(!PQ.empty())
    {
        int here = PQ.top().second;
        int dist_here = PQ.top().first;
        PQ.pop();
        // 느긋한 삭제 -> 불필요한 정점은 탐색하지 않는 방법 (PQ에 동일한 정점이 여러 개 들어있다면?)
        if(dist[here] != dist_here) continue;
        for(pair<int,int> there : adj[here])
        {
            int _there = there.second;
            int dist_there = there.first;
            if(dist[here] + dist_there < dist[_there])
            {
                dist[_there] = dist[here] + dist_there;
                PQ.push({dist[_there], _there});

                // 새로운 최단 경로가 발견되면 이전 부모 정보 삭제 후 갱신
                parent[_there].clear();
                parent[_there].push_back(here);
            }
            else if(dist[here] + dist_there == dist[_there])
            {
                // 최단 거리가 여러 개 일경우
                parent[_there].push_back(here);
            }
        }
    }
}
void trace_shortest_path(int node)
{
    if(node == 1) return;
    for (int prev : parent[node]) 
    {
        shortest_edges.push_back({prev, node});
        trace_shortest_path(prev);
    }
    return;
}
void solution()
{
    input();
    dijkstra(1);
    if(dist[n] == INF)
    {
        cout << -1 << "\n";
        return;
    }
    int retA = dist[n];
    int ret = -1;
    trace_shortest_path(n);
    for(pair<int,int> edge : shortest_edges)
    {
        int u = edge.first, v = edge.second, tu, tv;
        for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
            if (it->second == v) {
                tu = it->first;
                adj[u].erase(it);
                break;
            }
        }
        for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
            if (it->second == u) {
                tv = it->first;
                adj[v].erase(it);
                break;
            }
        }
        dijkstra(1);
        if(dist[n] == INF)
        {
            cout << -1 << "\n";
            return;
        }
        ret = max(ret, dist[n] - retA);
        adj[u].push_back({tu, v});
        adj[v].push_back({tv, u});
    }
    cout << ret << "\n";
    return;
}
int main()
{
    fastIO();
    solution();
    return 0;
}