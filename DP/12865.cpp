#include <bits/stdc++.h>
using namespace std;

// 평범한 배낭 (골드 5 - DP Alg.)
// https://www.acmicpc.net/problem/12865
int n, k, w, v, dp[100004];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int main()
{
    fastIO();
    cin >> n >> k;
    if(n<1 || n>100 || k<1 || k>100000) exit(0);
    
    for(int i=0; i<n; i++)
    {
        cin >> w >> v;
        for(int j=k; j>=w; j--)
        {
            dp[j] = max(dp[j], dp[j-w]+v);
        }
    }
    cout << dp[k] << "\n";
    return 0;
}