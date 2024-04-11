#include <bits/stdc++.h>
using namespace std;

// 삼성전자 코딩테스트 기출문제
// 연산자 끼워넣기 (Brute Force Alg.)
// https://www.acmicpc.net/problem/14888
typedef long long ll;
ll _max = -1e9, _min = 1e9;
int n, arr[12];
vector<char> v;
char oper[4] = {'+', '-', '*', '/'};
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void solution(vector<char>& vec)
{
    ll ret = arr[0];
    for(int i=1; i<n; i++)
    {
        if(vec[i-1] == '+')
        {
            ret += arr[i];
        } else if(vec[i-1] == '-')
        {
            ret -= arr[i];
        } else if(vec[i-1] == '*')
        {
            ret *= arr[i];
        } else if(vec[i-1] == '/')
        {
            ret /= arr[i];
        }
    }
    if(ret > _max) _max = ret;
    if(ret < _min) _min = ret;
    return;
}
// 순열 코드
void make_permutation(int n, int r, int depth)
{
    if(r == depth)
    {
        solution(v);
        return;
    }
    for(int i=depth; i<n; i++)
    {
        swap(v[i], v[depth]);
        make_permutation(n, r ,depth+1);
        swap(v[depth], v[i]);
    }
    return;
}
int main()
{
    fastIO();
    cin >> n;
    if(n<2 || n>11) exit(0);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        if(arr[i]<1 || arr[i]>100) exit(0);
    }
    for(int i=0; i<4; i++)
    {
        int cnt;
        cin >> cnt;
        for(int j=0; j<cnt; j++) v.push_back(oper[i]);
    }
    make_permutation(v.size(), v.size(), 0);
    cout << _max << "\n" << _min << "\n";
    return 0;
}