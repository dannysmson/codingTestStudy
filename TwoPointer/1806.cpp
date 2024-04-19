#include <bits/stdc++.h>
using namespace std;

// 부분합 (투 포인터 Alg.)
// https://acmicpc.net/problem/1806
typedef long long ll;
const int INF = 987654321;
int l, r, sum, arr[100001], _min = INF;
ll n, s;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int main()
{
    fastIO();
    cin >> n >> s;
    if(n<0 || n>100000 || s<0 || s>100000000) exit(0);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        if(arr[i] < 0 || arr[i] > 10000) exit(0);
    }
    while(l <= r)
    {
        if(sum >= s)
        {
            _min = min(_min, r-l);
            sum -= arr[l++];
        }
        else
        {
            if(r == n) break;
            sum += arr[r++];
        }
    }
    if(_min == INF) cout << 0 << "\n";
    else cout << _min << "\n";
    return 0;
}