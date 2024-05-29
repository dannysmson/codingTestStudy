#include <bits/stdc++.h>
using namespace std;

// 앱 (골드3 - Alg.)
// https://www.acmicpc.net/problem/7579
int n, m, sum;
int dp[10001];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int main()
{
    fastIO();
    cin >> n >> m;
    if(n<1 || n>100 || m<1 || m>10000000) exit(0);

    vector<int> a(n);
    vector<int> c(n);

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) 
    {
        cin >> c[i];
        sum += c[i];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=sum; j>=c[i]; j--)
        {
            dp[j] = max(dp[j], dp[j-c[i]] + a[i]);
        }
    }

    for(int i=0; i<=sum; i++)
    {
        if(dp[i] >= m) 
        {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}