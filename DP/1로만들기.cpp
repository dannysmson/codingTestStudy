#include <bits/stdc++.h>
using namespace std;

// 1로 만들기 (Dynamic Programming Alg.)
// 시간 제한: 1초, 메모리 제한: 128MB
// 정수 X, 사용할 수 있는 연산 4가지
// 1. X가 5로 나누어떨어지면 5로 나누기
// 2. X가 3으로 나누어떨어지면 3으로 나누기
// 3. X가 2로 나누어떨어지면 2로 나누기
// 4. X에서 1 빼기
// X가 주어졌을 때, 4가지 연산을 이용해서 1을 만들어야 함, 연산의 최소 횟수
int x, dp[30001];
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
    cin >> x;
    if(x<1 || x>30000) exit(0);
    fill(dp, dp+30001, INF);
    dp[1] = 0;
    for(int i=2; i<=x; i++)
    {
        if(i%5 == 0) dp[i] = min(dp[i], dp[i/5] + 1);
        if(i%3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
        if(i%2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        dp[i] = min(dp[i], dp[i-1] + 1);
    }
    cout << dp[x] << "\n";
    return 0;
}