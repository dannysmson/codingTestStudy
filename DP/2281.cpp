#include <bits/stdc++.h>
using namespace std;

// 데스노트 (골드3 - DP Alg.)
// https://www.acmicpc.net/problem/2281
int n, m, dp[1001][1001], arr[1001];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
/*int solution(int cnt, int len)
{
    if(cnt == n) return 0;
    int &ret = dp[cnt][len];
    if(ret != -1) return dp[cnt][len];

    // 한 칸 내려 쓸 때
    ret = (m - len + 1) * (m - len + 1) + solution(cnt+1, arr[cnt] + 1);
    
    // 같은 줄에 쓸 때
    if(len + arr[cnt] <= m)
    {
        ret = min(ret, solution(cnt+1, len + arr[cnt] + 1));
    }
    return ret;
}*/
int solution(int pos, int len)
{
    if(pos == n) return 0;
    // dp[pos][len]: pos개의 이름을 사용하여 len개의 칸을 사용한 것
    int &ret = dp[pos][len];
    if(ret != -1) return dp[pos][len];

    // 한 줄 띄어 쓸 때
    ret = (m - len + 1) * (m - len + 1) + solution(pos+1, arr[pos]+1);
    // 같은 줄에 쓸 때
    if(len + arr[pos] <= m)
    {
        ret = min(ret, solution(pos+1, len+arr[pos]+1));
    }
    return ret;
}
int main()
{
    fastIO();
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solution(1, arr[0]+1) << "\n";
    return 0;
}