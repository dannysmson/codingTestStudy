#include <bits/stdc++.h>
using namespace std;

// 바닥 공사 (Dynamic Programming Alg.)
// 시간 제한: 1초, 메모리 제한: 128MB
// 가로 길이 N, 세로 길이 2, 직사각형(2xN) 바닥에 1x2, 2x1, 2x2 덮개를 이용해 채움
// 바닥을 채우는 모든 경우의 수를 구하기
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
    if(n < 1 || n > 1000) exit(0);
    dp[1] = 1;
    dp[2] = 3;
    for(int i=3; i<=n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2] * 2) % 796796;
    }
    cout << dp[n] << "\n";
    return 0;
}