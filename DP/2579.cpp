#include <bits/stdc++.h>
using namespace std;

// 계단 오르기 (실버3 - DP Alg.)
// https://www.acmicpc.net/problem/2579
int n, dp[301];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int main()
{
    fastIO();
    cin >> n;   // 계단의 갯수
    if(n<1 || n>300) exit(0);
    
    vector<int> stairs(n);
    for(int i=0; i<n; i++)
    {
        cin >> stairs[i];
        if(stairs[i] < 1 || stairs[i] > 10000) exit(0);
    }

    dp[0] = 0;
    dp[1] = stairs[0];
    dp[2] = dp[1] + stairs[1];
    for(int i=3; i<=n; i++)
    {
        dp[i] = max(dp[i-2], dp[i-3] + stairs[i-2]) + stairs[i-1];
    }
    cout << dp[n] << "\n";
    return 0;
}
// n번째칸을 밟는 경우의 수
// 1. n-2칸 + n칸
// 2. n-3칸 + n-1칸 + n칸