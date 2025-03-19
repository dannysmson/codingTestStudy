#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// 16964 - DFS 스페셜 저지
int n, cnt;
vector<int> adj[100001];
vector<int> dfsOrder(100001, 0);
vector<int> order(100001, 0);
vector<int> ans(100001, 0);
bool visited[100001];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
bool cmp(int a, int b) 
{
    return order[a] < order[b];
}  
void input()
{
    cin >> n;
    for(int i=0; i<n-1; i++)
    {
        int vA, vB;
        cin >> vA >> vB;
        adj[vA].push_back(vB);
        adj[vB].push_back(vA);
    }
    for(int i=0; i<n; i++)
    {
        cin >> dfsOrder[i];
        order[dfsOrder[i]] = i;
    }
    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end(), cmp);
    return;
}
void dfs(int x)
{
    if(visited[x]) return;
    visited[x] = true;
    ans[cnt++] = x;
    for(int next : adj[x])
    {
        if(visited[next]) continue;
        dfs(next);
    }
    return;
}
int main()
{
    fastIO();
    input();
    dfs(1);
    cout << (ans == dfsOrder ? 1 : 0) << '\n';
    return 0;
}