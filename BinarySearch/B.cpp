#include <bits/stdc++.h>
using namespace std;

// 떡볶이 떡 만들기 (이진탐색 Alg.)
// 시간 제한: 2초, 메모리 제한: 128MB
// N개의 떡, 요청한 떡의 길이 M (1 <= N <= 1000000), (1 <= M <= 2000000000)
// 절단기의 높이를 H로 설정할 때, 떡의 길이가 H보다 길면 자르고, 잘린 부분의 합이 M이 되도록 하는 H구하기
typedef long long ll;
ll n, m, arr[1000004], lo, hi, mid, ret, _max;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void go()
{
    lo = 0;
    hi = _max;
    while(lo <= hi)
    {
        ll sum = 0;
        mid = (lo + hi) / 2;
        for(ll i=0; i<n; i++)
        {
            if(arr[i] > mid) sum += (arr[i] - mid);
        }
        if(sum >= m) 
        {
            ret = mid;
            lo = mid + 1;
        } else
        {
            hi = mid - 1;
        }
    }
    cout << ret << "\n";
}
int main()
{
    fastIO();
    cin >> n >> m;
    if(n<1 || n>1000000 || m<1 || m>2000000000) exit(0);
    for(ll i=0; i<n; i++) 
    {
        cin >> arr[i];
        _max = max(_max, arr[i]);
    }
    go();
    return 0;
}