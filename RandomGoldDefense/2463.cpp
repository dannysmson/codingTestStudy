#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int _MAX = 100004;
const int mod = 1e9;
int n, m;
ll ret, totalCost, node[_MAX], setSize[_MAX];
vector<pair<pair<ll,ll>, ll>> edge;
bool comp(pair<pair<ll,ll>, ll> a, pair<pair<ll,ll>, ll> b)
{
    return a.second > b.second;
}
int find(int u)
{
    if(u == node[u]) return u;
    return node[u] = find(node[u]);
}
void Union(int u, int v)
{
    u = find(u);
    v = find(v);
    node[u] = v;
    setSize[v] += setSize[u];
    setSize[u] = setSize[v];
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    // 분리집합 구현 위한 배열
    for(int i=0; i<=n; i++) 
    {
        node[i] = i;
        setSize[i] = 1;
    }
    for(int i=0; i<m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edge.push_back({{u, v}, w});
        totalCost += w;
    }
    // 가중치 기준 내림차순 정렬
    sort(edge.begin(), edge.end(), comp);
    
    for(int i=0; i<m; i++)
    {
        ll u = edge[i].first.first, v = edge[i].first.second;
        ll w = edge[i].second;
        
        ll rootU = find(u);
        ll rootV = find(v);
        
        if(rootU != rootV)
        {
            ret += (((setSize[rootU] * setSize[rootV]) % mod) * totalCost) % mod;
            ret %= mod;
            Union(rootU, rootV);
        }
        totalCost -= w;
    }
    cout << ret << "\n";
    return 0;
}