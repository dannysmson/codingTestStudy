#include <bits/stdc++.h>
using namespace std;

// 16947 - 서울 지하철 2호선
// 정점을 dfs로 먼저 싸이클을 찾고, bfs로 싸이클과의 거리를 구함
int n, a, b;
vector<int> adj[3001];
vector<int> dist(3001, -1);
vector<bool> visited(3001, false);
vector<int> parent(3001, -1);
int cycle_start = -1, cycle_end = -1;

bool dfs(int v, int par) 
{
    visited[v] = true;
    for (int u : adj[v]) 
    {
        if (u == par) continue; // 부모 정점은 건너뜀
        if (visited[u]) 
        {
            cycle_end = v; cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, v)) return true;
    }
    return false;
}

void find_cycle() 
{
    for (int i = 1; i <= n; i++) 
    {
        if (!visited[i] && dfs(i, -1)) break;
    }
    if (cycle_start == -1) return; // 싸이클 존재하지 않으면
    dist[cycle_start] = 0;
    // 싸이클 내 모든 정점의 dist 0 초기화
    for (int v = cycle_end; v != cycle_start; v = parent[v]) dist[v] = 0;
    return;
}

void bfs() {
    queue<int> que;
    for (int i = 1; i <= n; i++) 
    {
        if (dist[i] == 0) que.push(i);
    }
    while (!que.empty()) 
    {
        int v = que.front();
        que.pop();
        for (int u : adj[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                que.push(u);
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    find_cycle();
    bfs();

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";
    return 0;
}