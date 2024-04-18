#include <bits/stdc++.h>
using namespace std;

// (1,2,3 더하기 4 - DP Alg.)
// https://www.acmicpc.net/problem/15989
long long dp[10001][4];
int t, n;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int main()
{
    fastIO();
    cin >> t;
    
    dp[1][1] = 1;
    dp[2][1] = 1;   dp[2][2] = 1;
    dp[3][1] = 1;   dp[3][2] = 1;   dp[3][3] = 1;
    for(int i=4; i<=10000; i++)
    {
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }

    while(t--)
    {
        cin >> n;
        if(n<1 || n>10000) exit(0);
        cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
    }
    return 0;
}