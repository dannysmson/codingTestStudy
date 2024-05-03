#include <bits/stdc++.h>
using namespace std;

// 숨바꼭질3 (골드 5, DFS, BFS Alg.)
// https://www.acmicpc.net/problem/13549
int n, k, visited[100001];
// 위치 이동하는 데에 가중치가 다르기 때문에 우선순위 큐 사용
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void go(int start, int end)
{
    pq.push({0, start});
    while(!pq.empty())
    {
        int t = pq.top().first;
        int pos = pq.top().second;
        pq.pop();
        visited[pos] = 1;
        if(pos == end)
        {
            cout << t << "\n";
            return;
        }
        for(int num : {pos-1, pos+1, pos*2})
        {
            if(num < 0 || num >100000 || visited[num]) continue;
            if(num == pos * 2) pq.push({t, num});
            else pq.push({t+1, num});
        }
    }
    return;
}
int main()
{
    fastIO();
    cin >> n >> k;
    if(n<0 || n>100000 || k<0 || k>100000) exit(0);
    go(n, k);
    return 0;
}