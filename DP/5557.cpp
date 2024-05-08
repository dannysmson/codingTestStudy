#include <bits/stdc++.h>
using namespace std;

// 1학년 (골드 5. DP Alg.)
// https://www.acmicpc.net/problem/5557
typedef long long ll;
int n;
ll dp[101][21];
vector<int> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int main()
{
    fastIO();
    cin >> n;
    if(n<3 || n>100) exit(0);
    for(int i=1; i<=n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    dp[1][v[0]] = 1;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<=20; j++)
        {
            if(dp[i][j])
            {
                if(j+v[i] <= 20) dp[i+1][j+v[i]] += dp[i][j];
                if(j-v[i] >= 0) dp[i+1][j-v[i]] += dp[i][j];
            }
        }
    }
    cout << dp[n-1][v[n-1]] << "\n";
}