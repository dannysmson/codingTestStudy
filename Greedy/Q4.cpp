#include <bits/stdc++.h>
using namespace std;

// Q4. 만들 수 없는 금액 (Greedy Alg.)
// 시간 제한: 1초, 메모리 제한: 128MB
// N개의 동전을 이용하여 만들 수 없는 양의 정수 중 최솟값 구하기
int n, ret, arr[1001];
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
    if(n<1 || n>1000) exit(0);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        if(arr[i] < 1 || arr[i] > 1000000) exit(0);
    }
    sort(arr, arr+n);
    int ret = 1;
    for(int i=0; i<n; i++)
    {
        if(ret < arr[i]) break;
        ret += arr[i];
    }
    cout << ret << "\n";
    return 0;
}