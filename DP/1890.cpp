#include <bits/stdc++.h>
using namespace std;

// 점프 (실버 1 - DP Alg.)
// https://www.acmicpc.net/problem/1890
typedef long long ll;
ll dp[101][101];
int n, arr[101][101];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input()
{
    cin >> n;
    if(n<4 || n>100) exit(0);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) 
        {
            cin >> arr[i][j];
            if(arr[i][j] < 0 || arr[i][j] > 9) exit(0);
        }
    }
    return;
}
ll go(int y, int x)
{
    if(y == n-1 && x == n-1) return 1;
    if(y >= n || x >= n || arr[y][x] == 0) return 0;
    ll &ret = dp[y][x];
    if(ret != -1) return ret;
    return (ret = go(y, x + arr[y][x]) + go(y + arr[y][x], x));
}
int main()
{
    memset(dp, -1, sizeof(dp));
    fastIO();
    input();
    cout << go(0, 0) << "\n";
    return 0;
}