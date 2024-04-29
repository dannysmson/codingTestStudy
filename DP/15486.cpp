#include <bits/stdc++.h>
using namespace std;

// 퇴사2 (골드 5. DP Alg.)
// https://www.acmicpc.net/problem/15486
int n, dp[1500051], day, point, _max;
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
    if(n<1 || n>1500000) exit(0);

    for(int today = 1; today <= n; today++)
    {
        cin >> day >> point;
        if(dp[today] < dp[today-1]) dp[today] = dp[today-1];
        if(today + day > n + 1) continue;
        dp[today+day] = max(dp[today+day], dp[today]+point);
    }
    _max = max(dp[n], dp[n+1]);
    cout << _max << "\n";
    return 0;
}