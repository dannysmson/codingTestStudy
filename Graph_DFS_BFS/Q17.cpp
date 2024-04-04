#include <bits/stdc++.h>
using namespace std;

// 경쟁적 전염 (BFS Alg.)
// https://www.acmicpc.net/problem/18405
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, k, arr[201][201], visited[201][201];
int S, Y, X;
vector<pair<int, pair<int,int>>> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void bfs(int S, int Y, int X)
{
    int curTime = 0;
    while(curTime < S)
    {
        int vCnt = v.size();
        for(int i=0; i<vCnt; i++)
        {
            int curVirus = v[i].first;
            int curY = v[i].second.first;
            int curX = v[i].second.second;
            if(visited[curY][curX]) continue;
            visited[curY][curX] = 1;
            for(int i=0; i<4; i++)
            {
                int ny = curY + dy[i];
                int nx = curX + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >=n) continue;
                if(arr[ny][nx]) continue;
                arr[ny][nx] = curVirus;
                v.push_back({curVirus, {ny, nx}});
            }
        }
        if(arr[Y-1][X-1]) return;
        curTime++;
    }
}
int main()
{
    fastIO();
    cin >> n >> k;
    if(n<1 || n>200 || k<1 || k>1000) exit(0);
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] < 0 || arr[i][j] > k) exit(0);
            if(arr[i][j] != 0) v.push_back({arr[i][j], {i, j}});
        }
    }
    cin >> S >> Y >> X;
    if(S<0 || S>10000 || Y<1 || Y>n || X<1 || X>n) exit(0);

    sort(v.begin(), v.end());
    bfs(S, Y, X);
    cout << arr[Y-1][X-1] << "\n";
    return 0;
}