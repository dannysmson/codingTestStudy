#include <bits/stdc++.h>
using namespace std;

// 큰 수의 법칙
// Greedy Alg.

// 시간 제한 1초, 메모리 제한 128MB
// 크기가 N인 배열, 더하는 횟수 M번, 특정 인덱스 연속 더할 수 있는 횟수 K번 => 최대 크기 답 구하기
// 입력조건: (2 <= N <= 1000), (1 <= M <= 10000), (1 <= K <= 10000) 자연수
int n, m, k, ret, arr[1004];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void checkIO(int n, int m, int k)
{
    if(n < 2 || n > 1000 || m < 1 || m > 10000 || k < 1 || k > 10000) exit(0);
    return;
}
int main()
{
    fastIO();
    cin >> n >> m >> k;
    checkIO(n, m, k);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    while(1)
    {
        if(k >= m)
        {
            ret += (m * arr[n - 1]);
            break;
        } else
        {
            ret += (k * arr[n - 1]);
            ret += arr[n - 2];
            m -= (k + 1);
        }
    }
    cout << ret << "\n";
}