#include <bits/stdc++.h>
using namespace std;

// 사용자 정의 정렬 함수 만들어 사용하기
// first기준 내림차순, second기준 오름차순
vector<pair<int,int>> v;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.first > b.first;
}
int main()
{
    for(int i=1; i<=10; i++)
    {
        v.push_back(make_pair(i, i));
    }
    sort(v.begin(), v.end(), cmp);
    for(pair<int,int> tmp : v) 
    {
        cout << tmp.first << " : " << tmp.second << "\n";
    }
    return 0;
}