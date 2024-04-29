#include <bits/stdc++.h>
using namespace std;

// 기타리스트 (실버 1 - DP Alg.)
// https://www.acmicpc.net/problem/1495
int n, s, m, arr[51], dp[51][1001];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input()
{
    cin >> n >> s >> m;
    if(n<1 || n>50 || m<1 || m>1000 || s<0 || s >m) exit(0);
    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];  
    }
    return;
}
void solution()
{
    // 시작 볼륨
    dp[0][s] = 1;
    int diff;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(dp[i-1][j])
            {
                // 볼륨 증가
                diff = j + arr[i];
                if(diff <= m)
                {
                    dp[i][diff] = 1;
                }
                // 볼륨 감소
                diff = j - arr[i];
                if(diff >= 0)
                {
                    dp[i][diff] = 1;
                }
            }
        }
    }
    for(int i=m; i>=0; i--)
    {
        if(dp[n][i])
        {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
    return;
}
int main()
{
    fastIO();
    input();
    solution();
    return 0;
}