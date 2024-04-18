#include <bits/stdc++.h>
using namespace std;

// 돌 게임 (실버 5 Dynamic Programming Alg.)
// https://www.acmicpc.net/problem/9655
int n, dp[1001];
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

    dp[1] = 1;  // 1인 경우 상근, -1인 경우 창영
    for(int i=1; i<n; i++)
    {
        if(i+1 <= n)
        {
            dp[i+1] = (dp[i] == 1 ? -1 : 1);
        }
        if(i+3 <= n)
        {
            dp[i+3] = (dp[i] == 1 ? -1 : 1);
        }
    }
    if(dp[n] == 1) cout << "SK" << "\n";
    else cout << "CY" << "\n";
    return 0;
}