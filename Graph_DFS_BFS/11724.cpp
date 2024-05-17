#include <bits/stdc++.h>
using namespace std;

// 연결 요소의 갯수 (실버 2 - DFS Alg.)
// https://www.acmicpc.net/problem/11724
int n, m, from, to, visited[1001], ret;
vector<int> graph[1001];
queue<int> q;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int main()
{
    fastIO();
    cin >> n >> m;
    if(n<1 || n>1000 || m<0 || m>(n*(n-1)/2)) exit(0);

    for(int i=0; i<m; i++)
    {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for(int i=1; i<=n; i++)
    {
        if(visited[i]) continue;
        q.push(i);
        visited[i] = 1;
        while(!q.empty())
        {
            int to = q.front();
            q.pop();
            for(int next : graph[to])
            {
                if(visited[next]) continue;
                q.push(next);
                visited[next] = 1;
            }
        }
        ret++;
    }
    cout << ret << "\n";
    return 0;
}