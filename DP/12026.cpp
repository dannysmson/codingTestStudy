#include <bits/stdc++.h>
using namespace std;

// BOJ거리 (실버 1 - DP Alg.)
// https://www.acmicpc.net/problem/12026
const int INF = 987654321;
int n, dp[1001];
string str;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int main()
{
    fastIO();
    fill(dp, dp+1001, INF);
    cin >> n;
    if(n<1 || n>1000) exit(0);
    cin >> str;

    dp[1] = 0;
    for(int i=0; i<n; i++)
    {
        if(str[i] == 'B')
        {
            for(int j=i+1; j<n; j++)
            {
                if(str[j] == 'O')
                {
                    dp[j+1] = min(dp[j+1], (j-i)*(j-i)+dp[i+1]);
                }
            }
        }
        else if(str[i] == 'O')
        {
            for(int j=i+1; j<n; j++)
            {
                if(str[j] == 'J')
                {
                    dp[j+1] = min(dp[j+1], (j-i)*(j-i)+dp[i+1]);
                }
            }
        }
        else if(str[i] == 'J')
        {
            for(int j=i+1; j<n; j++)
            {
                if(str[j] == 'B')
                {
                    dp[j+1] = min(dp[j+1], (j-i)*(j-i)+dp[i+1]);
                }
            }
        }
    }
    if(dp[n] == INF) cout << -1 << "\n";
    else cout << dp[n] << "\n";
    return 0;
}