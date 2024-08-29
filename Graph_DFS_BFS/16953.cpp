#include <bits/stdc++.h>
using namespace std;

// A -> B (실버 2)
// https://www.acmicpc.net/problem/16953
// 2를 곱하거나, 1을 수의 오른쪽에 추가하는 연산을 통해 A를 B로 변환
typedef long long ll;
const int INF = 987654321;
ll A, B, ret = INF;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void dfs(ll num, ll cnt)
{
    if(num > B) return;
    if(num == B)
    {
        ret = min(ret, cnt);
        return;
    }
    dfs(num*2, cnt+1);
    dfs(num*10+1, cnt+1);
}
int main()
{
    fastIO();
    cin >> A >> B;
    dfs(A, 1);
    if(ret == INF) ret = -1;
    cout << ret << "\n";
    return 0;
}