#include <bits/stdc++.h>
using namespace std;

// 택배 배달과 수거하기
typedef long long ll;
void fastIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
ll solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    ll answer = 0;
    int give = 0;
    int take = 0;

    for(ll i=n-1; i>=0; i--)
    {
        if(deliveries[i] || pickups[i])
        {
            ll cnt = 0;
            while(give < deliveries[i] || take < pickups[i])
            {
                cnt++;
                give += cap;
                take += cap;
            }
            give -= deliveries[i];
            take -= pickups[i];
            answer += (ll)((i + 1) * cnt * 2);
        }
    }
    return answer;
}
int main()
{
    fastIO();
    // 프로그래머스 예제 입력 (solution 함수만 구현)
    vector<int> deliveries = {1, 0, 2, 0, 1, 0, 2};
    vector<int> pickups = {0, 2, 0, 1, 0, 2, 0};
    cout << solution(2, 7, deliveries, pickups) << "\n";
    return 0;
}