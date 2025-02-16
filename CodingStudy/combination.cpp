#include <bits/stdc++.h>
using namespace std;

// combination 조합 구현
int n=5, r=3, arr[5] = {1,2,3,4,5};
void print(vector<int> v)
{
    for(int num : v) cout << num << " ";
    cout << "\n";
    return;
}
void combi(int start, vector<int> v)
{
    if(v.size() == r)
    {
        print(v);
        return;
    }
    for(int i=start+1; i<n; i++)
    {
        v.push_back(arr[i]);
        combi(i, v);
        v.pop_back();
    }
}
int main()
{
    vector<int> v;
    combi(-1, v);
    return 0;
}