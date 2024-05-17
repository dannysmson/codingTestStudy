#include <bits/stdc++.h>
using namespace std;

// 링크와 스타트 (골드 5 - Alg.)
// https://www.acmicpc.net/problem/15661
int n, arr[21][21], ret = 987654321;
vector<int> teamL;
vector<int> teamS;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int go(vector<int> &v)
{
    int tmp = 0;
    for(int i=0; i<v.size()-1; i++)
    {
        for(int j=i+1; j<v.size(); j++)
        {
            tmp += arr[v[i]][v[j]];
            tmp += arr[v[j]][v[i]];
        }
    }
    return tmp;
}
int main()
{
    fastIO();
    cin >> n;
    if(n<4 || n>20) exit(0);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<(1<<n); i++)
    {
        // 비트마스킹, 1이면 team Link에, 0이면 team Start에 포함
        for(int j=0; j<n; j++)
        {
            if(i & (1 << j)) teamL.push_back(j);
            else teamS.push_back(j);
        }
        if(teamL.size() == 0 || teamS.size() == 0) continue;
        int sumL = go(teamL);
        int sumS = go(teamS);
        ret = min(ret, abs(sumL-sumS));
        teamL.clear();
        teamS.clear();
    }
    cout << ret << "\n";
    return 0;
}