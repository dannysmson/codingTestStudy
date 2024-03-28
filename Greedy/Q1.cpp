#include <bits/stdc++.h>
using namespace std;

// Q1. 모험가 길드 (Greedy Alg.)
// 시간 제한: 1초, 메모리 제한: 128MB
// 모험가N명, N명의 공포도가 주어졌을 때, 공포도가 X인 모험가는 X명 이상으로 구성한 그룹에 참여해야 함
// 총 몇개의 그룹으로 구성할 수 있는지
int n, ret, cnt, arr[100001];
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
    if(n<1 || n>100000) exit(0);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    cnt = 0;
    for(int i=0; i<n; i++)      // 오름차순 정렬 후, 현재 그룹에 속한 인원 수가 현재 공포도 보다 높으면
    {
        cnt += 1;
        if(arr[i] <= cnt)
        {
            ret++;
            cnt = 0;
        }
    }
    return 0;
}