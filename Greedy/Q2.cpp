#include <bits/stdc++.h>
using namespace std;

// Q2. 곱하기 혹은 더하기 (Greedy Alg.)
// 시간 제한: 1초, 메모리 제한: 128MB
// (0~9)로만 이루어진 문자열이 주어졌을 때
// 왼쪽에서 오른쪽으로 숫자를 확인하여 '+', 'x'연산을 넣어 만들 수 있는 최댓값
string str;
int arr[21];
long long ret;
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
    int _size = str.size();
    if(_size < 1 || _size > 20) exit(0);
    for(int i=0; i<_size; i++)
    {
        arr[i] = (int)(str[i] - '0');
    }
    ret = arr[0];
    for(int i=1; i<_size; i++)  // 결과 값이나 숫자가 0이면 +, 아니면 *
    {
        if(ret == 0 || arr[i] == 0) ret += arr[i];
        else ret *= arr[i];
    }
    cout << ret << "\n";
    return 0;
}