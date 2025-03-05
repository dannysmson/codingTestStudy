#include <bits/stdc++.h>
using namespace std;

// RandomGoldDefense/2014
// 자료구조, 우선순위 큐
int n, k;
vector<int> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
void inputError()
{
    if(n < 1 || n > 1000000 || k < 1 || k > 1000000) exit(0);
    return;
}
void input()
{
    cin >> k >> n;
    inputError();
    for(int i=0; i<k; i++)
    {
        int num;
        cin >> num;
        if(num < 1 || num > 541) exit(0);
        v.push_back(num);
    }
}
void solution()
{
    input();
    sort(v.begin(), v.end());
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    set<long long> visited;

    for(int i=0; i<k; i++)
    {
        pq.push(v[i]);
        visited.insert(v[i]);
    }
    
    long long ret = 0;
    for(int i=0; i<n; i++)
    {
        ret = pq.top();
        pq.pop();

        for(int j=0; j<k; j++)
        {
            long long num = ret * v[j];
            if(visited.count(num) == 0) // 중복 제거
            {
                pq.push(num);
                visited.insert(num);
            }
            if(ret % v[j] == 0) break;
        }
    }
    cout << ret << "\n";
}
int main()
{
    fastIO();
    solution();
    return 0;
}
