#include <bits/stdc++.h>
using namespace std;

// c++ 순열 로직
// 재귀함수 사용하여 구현
vector<int> v;
void print(vector<int> &v)
{
    for(int i=0; i<3; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    return;
}
void makePermutation(int n, int r, int depth)
{
    if(r == depth)
    {
        print(v);
        return;
    }
    for(int i=depth; i<n; i++)
    {
        swap(v[i], v[depth]);
        makePermutation(n, r, depth + 1);
        swap(v[i], v[depth]);
    }
    return;
}
int main()
{
    for(int i=1; i<=5; i++) v.push_back(i);
    makePermutation(5, 3, 0);
    return 0;
}