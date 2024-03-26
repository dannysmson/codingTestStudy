#include <bits/stdc++.h>
using namespace std;

// 개미 전사 (Dynamic Programming Alg.)
// 시간 제한: 1초, 메모리 제한: 128MB
// N개의 식량창고, 최대한 많은 식량을 약탈해야함
// 약탈조건: 인접한 칸의 식량을 약탈하지 못함
int n, arr[104], dp[104];
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
    if(n<3 || n>100) exit(0);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        if(arr[i] < 0 || arr[i] > 1000) exit(0);
    }
    dp[0] = 0;
    dp[1] = max(dp[0], arr[1]);
    for(int i=2; i<n; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
    }
    cout << dp[n-1] << "\n";
    return 0;
}