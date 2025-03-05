#include <bits/stdc++.h>
using namespace std;

// 서강그라운드
// dijkstra, floyd-warshall Alg.

const int INF = 1e9;
int n, m, r, ret;
int item[101];
int dist[101][101];
void fastIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void input()
{
    cin >> n >> m >> r;
    if(n < 1 || n > 100 || m < 1 || m > 100 || r < 1 || r > 100) exit(0);
    for(int i=1; i<=n; i++) cin >> item[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i == j) continue;
            dist[i][j] = INF;
        }
    }
    for(int i=0; i<r; i++)
    {
        int cityA, cityB, l;
        cin >> cityA >> cityB >> l;
        dist[cityA][cityB] = l;
        dist[cityB][cityA] = l;
    }
    return;
}
void solution()
{
    input();
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        int sum = 0;
        for(int j=1; j<=n; j++)
        {
            if(dist[i][j] <= m) sum += item[j];
        }
        ret = max(ret, sum);
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