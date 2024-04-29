#include <bits/stdc++.h>
using namespace std;

// 크리보드 (골드 5 - DP Alg.)
// https://www.acmicpc.net/problem/11058
typedef long long ll;
ll dp[101];
int n;
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
    if(n<1 || n>100) exit(0);

    for(int i=1; i<=n; i++)
    {
        dp[i] = dp[i-1] + 1;
        for(int j=3; j<i; j++)
        {
            dp[i] = max(dp[i], dp[i-j]*(j-1));
        }
    }
    cout << dp[n] << "\n";
    return 0;
}