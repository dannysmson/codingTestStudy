#include <bits/stdc++.h>
using namespace std;

// 1차원 배열 회전 연습
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    rotate(v.begin(), v.begin() + 1, v.end());
    for(int num : v) cout << num << " ";
    cout << "\n";
    rotate(v.rbegin(), v.rbegin()+1, v.rend());
    for(int num : v) cout << num << " ";
    cout << "\n";
    return 0;
}