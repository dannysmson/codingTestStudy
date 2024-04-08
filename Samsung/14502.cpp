#include <bits/stdc++.h>
using namespace std;

// 삼성전자 코딩테스트 기출문제
// 연구소 (DFS Alg.)
// https://www.acmicpc.net/problem/14502
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, arr[8][8], check[8][8], visited[8][8], ret;
vector<pair<int,int>> zero_v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void dfs(int y, int x)
{
    visited[y][x] = 1;
    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || check[ny][nx] == 1) continue;
        check[ny][nx] = 2;
        dfs(ny, nx);
    }
}
int main()
{
    fastIO();
    cin >> n >> m;
    if(n<3 || n>8 || m<3 || m>8) exit(0);
    memset(arr, -1, sizeof(arr));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 0)
            {
                pair<int,int> zero;
                zero.first = i;
                zero.second = j;
                zero_v.push_back(zero);
            }
        }
    }
    int zSize = zero_v.size();

    // 0, 즉 빈칸인 부분들 중에서 조합 알고리즘을 이용해서 3곳을 골라 벽으로 만들고 dfs 진행
    for(int i=0; i<zSize; i++)
    {
        for(int j=i+1; j<zSize; j++)
        {
            for(int k=j+1; k<zSize; k++)
            {
                copy(&arr[0][0], &arr[0][0]+64, &check[0][0]);
                check[zero_v[i].first][zero_v[i].second] = 1;
                check[zero_v[j].first][zero_v[j].second] = 1;
                check[zero_v[k].first][zero_v[k].second] = 1;
                
                memset(visited, 0, sizeof(visited));

                for(int a=0; a<n; a++)
                {
                    for(int b=0; b<m; b++)
                    {
                        if(!visited[a][b] && check[a][b] == 2) dfs(a, b);
                    }
                }
                int cnt = count(&check[0][0], &check[0][0] + 64, 0);
                ret = max(ret, cnt);
            }
        }
    }
    cout << ret << "\n";
    return 0;
}