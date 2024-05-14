#include <bits/stdc++.h>
using namespace std;

// 강의실 배정 (골드 5 - Greedy Alg.)
// https://www.acmicpc.net/problem/11000
typedef long long ll;
ll n;
vector<pair<ll,ll>> v;
priority_queue<ll, vector<ll>, greater<ll>> pq;
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
    if(n < 1 || n > 200000) exit(0);

    for(int i=0; i<n; i++)
    {
        ll s, t;
        cin >> s >> t;
        v.push_back({s, t});
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++)
    {
        pq.push(v[i].second);
        if(pq.top() <= v[i].first) pq.pop();
    }
    cout << pq.size() << "\n";
    return 0;
}