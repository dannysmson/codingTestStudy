#include <bits/stdc++.h>
using namespace std;

// 위에서 아래로 (Sorting Alg.)

// 시간 제한: 1초, 메모리 제한: 128MB
// 하나의 수열이 주어졌을 때, 큰 수부터 작은 수의 순서로 정렬 (내림차순)
// 입력조건: 1 <= N <= 500

// 기본적인 정렬 문제로, n의 범위가 500이기 때문에 어떤 정렬 알고리즘을 사용해도 괜찮지만, 퀵 정렬을 기반으로 한 c++의 정렬 라이브러리 사용
int n, arr[501];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int main()
{
    cin >> n;
    if(n<1 || n>500) exit(0);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n, greater<int>());
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}