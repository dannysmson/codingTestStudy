#include <bits/stdc++.h>
using namespace std;

// 특정 거리의 도시 찾기 (BFS Alg.)
// https://www.acmicpc.net/problem/18352
int n, m, k, x, from, to, dist[300001], flag;
vector<int> v[300001];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void go(int start)
{
    dist[start] = 0;
    queue<int> que;
    que.push(start);
    while(que.size())
    {
        int here = que.front(); que.pop();
        for(int there : v[here])
        {
            if(dist[there] == -1)
            {
                dist[there] = dist[here] + 1;
                que.push(there);
            }
        }
    }
    return;
}
int main()
{
    fastIO();
    fill(dist, dist+300001, -1);
    cin >> n >> m >> k >> x;
    if(n<2 || n>300000 || m<1 || m>1000000 || k<1 || k>300000 || x<1 || x>n) exit(0);
    
    for(int i=0; i<m; i++)
    {
        cin >> from >> to;
        v[from].push_back(to);
    }
    go(x);
    for(int i=1; i<=n; i++)
    {
        if(i == x) continue;
        if(dist[i] == k) 
        {
            cout << i << "\n";
            flag++;
        }
    }
    if(flag==0) cout << -1 << "\n";
    return 0;
}