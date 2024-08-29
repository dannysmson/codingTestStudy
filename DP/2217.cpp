#include <bits/stdc++.h>
using namespace std;

// 로프(실버 4)
// https://www.acmicpc.net/problem/2217
int rope[100001], n, _max, cur;
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
    for(int i=0; i<n; i++)
    {
        cin >> rope[i];
    }
    sort(rope, rope + n, greater<int>());
    _max = rope[0];
    for(int i=1; i<n; i++)
    {
        cur = rope[i] * (i + 1);
        if(cur > _max) _max = cur;
    }
    cout << _max << "\n";
    return 0;
}
