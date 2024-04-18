#include <bits/stdc++.h>
using namespace std;

// 이친수 (실버 3 Dynamic Programming Alg.)
// https://www.acmicpc.net/problem/2193
int n;
long long dp[91];
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
    if(n<1 || n>90) exit(0);

    dp[1] = 1;
    dp[2] = 1;
    for(int i=3; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << "\n";
    return 0;
}