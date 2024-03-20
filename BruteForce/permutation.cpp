#include <bits/stdc++.h>
using namespace std;

// c++ 순열 로직
// next_permutation[from, to) 사용
// 오름차순 정렬이 되어 있어야 함
int main()
{
    vector<int> v = {3, 1, 2 ,4};
    sort(v.begin(), v.end());
    do
    {
        for(int i=0; i<3; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));
    
    return 0;
}