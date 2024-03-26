#include <bits/stdc++.h>
using namespace std;

// 효율적인 화폐 구성 (Dynamic Programming Alg.)
// N가지 종류의 화폐, 화폐 갯수를 최소화 해서 합이 M원이 되도록
// 불가능한 경우 -1 출력
int n, m, money, dp[10001];
const int INF = 987654321;
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
    if(n<1 || n>100 || m<1 || m>10000) exit(0);
    fill(dp, dp+10001, INF);
    dp[0] = 0;
    for(int i=0; i<n; i++)
    {
        cin >> money;
        for(int j=money; j<=m; j++)
        {
            dp[j] = min(dp[j], dp[j-money] + 1);
        }
    }
    if(dp[m] == INF) cout << -1 << "\n"; // 합이 M이 불가능한 경우
    else cout << dp[m] << "\n";
    return 0;
}