#include <bits/stdc++.h>
using namespace std;

// 삼성전자 코딩테스트 기출문제
// 퇴사 (Dynamic Programming Alg.)
// https://www.acmicpc.net/problem/14501
int n, dp[16], t[16], p[16], _max;
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
    if(n<1 || n>15) exit(0);
    for(int i=0; i<n; i++)
    {
        cin >> t[i] >> p[i];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i+t[i]; j<=n; j++)
        {
            dp[j] = max(dp[j], dp[i]+p[i]);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}