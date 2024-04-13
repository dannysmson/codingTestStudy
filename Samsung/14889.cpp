#include <bits/stdc++.h>
using namespace std;

// 삼성전자 코딩테스트 기출문제
// 스타트와 링크 (Brute Force Alg. -조합) 
// https://www.acmicpc.net/problem/14889
int n, arr[21][21], ret=987654321;
vector<int> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void check(vector<int> &v)
{
    vector<int> v1, v2;
    int sum1 = 0, sum2 = 0;
    for(int i=0; i<n; i++)
    {
        if(find(v.begin(), v.end(), i) == v.end()) v2.push_back(i);
        else v1.push_back(i);
    }
    for(int i=0; i<v1.size(); i++)
    {
        for(int j=i+1; j<v1.size(); j++)
        {
            sum1 += arr[v1[i]][v1[j]];
            sum1 += arr[v1[j]][v1[i]];
        }
    }
    for(int i=0; i<v2.size(); i++)
    {
        for(int j=i+1; j<v2.size(); j++)
        {
            sum2 += arr[v2[i]][v2[j]];
            sum2 += arr[v2[j]][v2[i]];
        }
    }
    ret = min(ret, abs(sum1-sum2));
    return;
}
void combi(int start, vector<int> &v)
{
    if(v.size() == n/2)
    {
        check(v);
        return;
    }
    for(int i=start+1; i<n; i++)
    {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}
int main()
{
    fastIO();
    cin >> n;
    if(n<4 || n>20 || n%2 != 0) exit(0);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >>arr[i][j];
        }
    }
    combi(-1, v);
    cout << ret << "\n";
    return 0;
}