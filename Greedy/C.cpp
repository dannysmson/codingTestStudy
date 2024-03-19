#include <bits/stdc++.h>
using namespace std;

// 1이 될 때까지
// Greedy Alg.

// 시간 제한 1초, 메모리 제한 128MB
// 어떤 수 N이 1이 될 때까지 두 과정 중 하나를 반복하여 실행 (최소 횟수 구하기)
// N에서 1 빼기 or N을 K로 나누기
// 입력조건: (2 <= N <= 100000), (2 <= K <= 100000)
int n, k, ret;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void checkIO(int n, int k)
{
    if(n < 2 || n > 100000 || k < 2 || k > 100000) exit(0);
    return;
}
int main()
{
    fastIO();
    cin >> n >> k;
    checkIO(n, k);
    while(1)
    {
        if(n == 1) break;
        if(n % k == 0) 
        {
            n /= k;
            ret++;
        } else
        {
            n -= 1;
            ret++;
        }
    }
    cout << ret << "\n";
    return 0;
}