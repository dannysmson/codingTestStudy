#include <bits/stdc++.h>
using namespace std;

// 암호코드 (골드 5 - DP Alg.)
// https://www.acmicpc.net/problem/2011
string str;
int dp[5001];
const int MOD = 1e6;
// dp 정의 : dp[n] = n번째 숫자까지 읽을 수 있는 단어의 갯수
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void solution(string str)
{
    dp[0] = dp[1] = 1;
    if(str[0] == '0')
    {
        cout << 0 << "\n";
        return;
    }
    for(int i=2; i<=str.size(); i++)
    {
        if(str[i-1] != '0')
        {
            dp[i] = (dp[i-1] + dp[i]) % MOD;
        }
        int num = str[i-1]-'0' + (str[i-2]-'0') * 10;
        if(num >= 10 && num <= 26)
        {
            dp[i] = (dp[i-2] + dp[i]) % MOD;
        }
    }
    cout << dp[str.size()] << "\n";
    return;
}
int main()
{
    fastIO();
    cin >> str;
    solution(str);
    return 0;
}