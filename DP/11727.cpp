#include <bits/stdc++.h>
using namespace std;

// 2xn 타일링 2 (실버 3 - DP Alg.)
// https://www.acmicpc.net/problem/11727
typedef long long ll;
ll n, dp[1001];
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
    if(n<1 || n>1000) exit(0);
    dp[1] = 1; dp[2] = 3;
    for(int i=3; i<=n; i++)
    {
        dp[i] = (dp[i-1] + 2 * dp[i-2])%10007;
    }
    cout << dp[n] << "\n";
    return 0;
}