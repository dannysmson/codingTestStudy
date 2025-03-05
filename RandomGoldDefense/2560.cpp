#include <bits/stdc++.h>
using namespace std;

// 짚신벌레
typedef long long ll;
int a, b, d, N;
ll ret;
void fastIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    return;
}
void input()
{
    cin >> a >> b >> d >> N;
    if(a < 1 || a > 10000 || b < 1 || b > 10000 || d < 1 || d > 10000 || N < 1 || N > 1000000) exit(0);
    return;
}
void solution()
{
    input();
    vector<ll> dp(N+1, 0);
    dp[0] = 1;
    for(int day=1; day<=N; day++)
    {
        if(day < a) dp[day] = dp[day - 1];
        else
        {
            dp[day] = (dp[day - 1] + dp[day - a]) % 1000;
            if(day >= b) 
            {
                dp[day] = (dp[day] - dp[day - b] + 1000) % 1000;
            }
        }
    }
    if(N >= d)
    {
        dp[N] = (dp[N] - dp[N - d] + 1000) % 1000;
    }
    cout << dp[N] << "\n";
    return;
}
int main()
{
    fastIO();
    solution();
    return 0;
}