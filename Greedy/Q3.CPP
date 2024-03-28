#include <bits/stdc++.h>
using namespace std;

// Q3. 문자열 뒤집기 (Greedy Alg.)
// 0과1로만 이루어진 문자열에서 연속된 하나 이상의 숫자를 뒤집어 모두 0 / 모두 1로 변환하려함
// 최소 횟수 구하기
int ret1, ret2;
string str;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int main()
{
    fastIO();
    cin >> str;
    if(str[0] == '1') ret1++;
    else ret2++;
    for(int i=0; i<str.size()-1; i++)
    {
        if(str[i] != str[i+1])
        {
            if(str[i+1] == '1') ret1++;
            else ret2++;
        }
    }
    cout << min(ret1, ret2) << "\n";
    return 0;
}