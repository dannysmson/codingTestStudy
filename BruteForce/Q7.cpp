#include <bits/stdc++.h>
using namespace std;

// 럭키 스트레이트 (Brute Force Alg.)
// 시간 제한: 1초, 메모리 제한: 128MB
// 점수 N(짝수 자릿수)이 주어졌을 때, 왼쪽 자릿수의 합과 오른쪽 자릿수의 합이 같으면 LUCKY, 다르면 READY 출력
string n;
int sum_front, sum_back;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int main()
{
    fastIO();
    cin >> n;
    int _size = n.size();
    for(int i=0; i<_size/2; i++) sum_front += (n[i] - '0');
    for(int i=_size/2; i<_size; i++) sum_back += (n[i] - '0');
    if(sum_front == sum_back) cout << "LUCKY" << "\n";
    else cout << "READY" << "\n";
    return 0;
}