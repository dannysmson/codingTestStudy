#include <bits/stdc++.h>
using namespace std;

// 감소하는 수 (골드 5. Brute Force Alg.)
// https://www.acmicpc.net/problem/1038
typedef long long ll;
ll n, arr[1000001], idx, ret = 9;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
ll solution(ll n)
{
    queue<string> que;
    if(n<10) return n;
    que.push("1");
    que.push("2");
    que.push("3");
    que.push("4");
    que.push("5");
    que.push("6");
    que.push("7");
    que.push("8");
    que.push("9");
    while(que.size())
    {
        string cur = que.front(); que.pop();
        int len = cur.size();
        int idx = cur[len-1] - '0';
        for(int i=0; i<idx; i++)
        {
            string next = cur + to_string(i);
            ret++;
            if(ret == n)
            {
                return stoll(next);
            }
            que.push(next);
        }
    }
    return -1;
}
int main()
{
    fastIO();
    cin >> n;
    if(n<0 || n>1000000) exit(0);
    cout << solution(n) << "\n";
    return 0;
}