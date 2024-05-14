#include <bits/stdc++.h>
using namespace std;

// 거스름돈 (실버 5 - Greedy Alg.)
// https://www.acmicpc.net/problem/14916
int n, ret;
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
    if(n<1 || n>100000) exit(0);
    int cnt = n / 5;
    while(1)
    {
        int tmp = n;
        int cnt2 = cnt;
        tmp = tmp - (cnt * 5);
        if(tmp % 2 == 0)
        {
            cnt2 += tmp / 2;
            ret = cnt2;
            break;
        }
        if(cnt == 0)
        {
            ret = -1;
            break;
        }
        cnt--;
    }
    cout << ret << "\n";
    return 0;
}