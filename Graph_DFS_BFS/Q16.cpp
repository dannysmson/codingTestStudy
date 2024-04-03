#include <bits/stdc++.h>
using namespace std;

// 삼성전자 SW 역량테스트
// 연구소 (DFS Alg.)
// https://www.acmicpc.net/problem/14502
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, arr[8][8], tmp[8][8], visited[8][8], ret;
vector<pair<int,int>> zero_vector;
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
        if(ny < 0 || ny >=n || nx < 0 || nx >= m) continue;
        if(visited[ny][nx] || tmp[ny][nx] == 1) continue;
        tmp[ny][nx] = 2;
        dfs(ny, nx);
    }
}
int main()
{
    fastIO();
    cin >> n >> m;
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
                zero_vector.push_back(zero);
            }
        }
    }

    int _size = zero_vector.size();
    // 0인 좌표들만 따로 벡터에 담아, 조합 알고리즘을 이용하여 3개를 선택
    for(int i=0; i<_size; i++)
    {
        for(int j=i+1; j<_size; j++)
        {
            for(int k=j+1; k<_size; k++)
            {
                copy(&arr[0][0], &arr[0][0]+64, &tmp[0][0]);
                tmp[zero_vector[i].first][zero_vector[i].second] = 1;
                tmp[zero_vector[j].first][zero_vector[j].second] = 1;
                tmp[zero_vector[k].first][zero_vector[k].second] = 1;

                memset(visited, 0, sizeof(visited));
                for(int a=0; a<n; a++)
                {
                    for(int b=0; b<m; b++)
                    {
                        if(!visited[a][b] && tmp[a][b] == 2) dfs(a, b);
                    }
                }
                int cnt = count(&tmp[0][0], &tmp[0][0]+64, 0);
                ret = max(ret, cnt);
            }
        }
    }
    cout << ret << "\n";
    return 0;
}