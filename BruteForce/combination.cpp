#include <bits/stdc++.h>
using namespace std;

// c++ 조합 구현
// 반복문 사용하여 구현 (3개이하 선택 시 유용)
int n = 5;
int main()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            for(int k=j+1; k<=n; k++)
            {
                cout << i << " : " << j << " : " << k << "\n";
            }
        }
    }
    return 0;
}