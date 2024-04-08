#include <bits/stdc++.h>
using namespace std;

// 삼성전자 코딩테스트 기출문제
// 시험 감독
// https://www.acmicpc.net/problem/13458
typedef long long ll;
ll n, b, c, arr[1000001], ret;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void checkIO(int num)
{
    if(num<1 || num>1000000) exit(0);
    return;
}
int main()
{
    fastIO();
    cin >> n;
    checkIO(n);
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
        checkIO(arr[i]);
    }
    cin >> b >> c;
    for(ll i=0; i<n; i++)
    {
        arr[i] -= b; ret++;
        if(arr[i] > 0)
        {
            if(arr[i] % c) ret += (arr[i]/c + 1);
            else ret += (arr[i]/c);
        }
    }
    cout << ret << "\n";
    return 0;
}