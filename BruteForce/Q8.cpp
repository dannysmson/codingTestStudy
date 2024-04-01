#include <bits/stdc++.h>
using namespace std;

// 문자열 재정렬 (Brute Force Alg.)
// 시간 제한: 1초, 메모리 제한: 128MB
// 알파벳 대문자, 숫자0~9로만 구성된 문자열
// 모든 알파벳을 오름차순으로 정렬하여 출력후, 모든 숫자를 더한 값을 이어서 출력

int _size, _sum, idx;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int main()
{
    string s, str="";
    fastIO();
    cin >> s;
    _size = s.size();
    if(_size < 1 || _size > 10000) exit(0);
    for(int i=0; i<_size; i++)
    {
        if(s[i] >= '0' && s[i] <= '9') _sum += ((int)(s[i] - '0'));
        else str += s[i];
    }
    sort(str.begin(), str.end());
    cout << str << _sum << "\n";
    return 0;
}