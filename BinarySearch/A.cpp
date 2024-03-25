#include <bits/stdc++.h>
using namespace std;

// 부품 찾기 (이진 탐색 Alg.)

// 시간 제한: 1초, 메모리 제한: 128MB
// N개의 부품중 M개의 부품이 있는지 확인하는 문제
// M개의 부품에 대해 각 부품이 있으면 yes 없으면 no 출력
// (1 <= N <= 1,000,000), (1 <= M <= 100,000)
// N의 범위가 크기에 이진 탐색을 사용하면 유리
// 이진 탐색 시간 복잡도: O(M x logN) => 최대 200만
// 배열 정렬 시간 복잡도: O(N x logN) => 최대 2000만
// 오히려 배열 정렬에 시간소요가 더 크며, 최종 시간 복잡도: O((M+N) x logN)
int n, m, target, arr[1000001];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void binary_search(int *arr, int target, int l, int r)
{
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(arr[mid] == target) 
        {
            cout << "yes" << " ";
            return;
        }
        if(arr[mid] > target) r = mid - 1;
        else l = mid + 1;
    }
    cout << "no" << " ";
    return;
}
int main()
{
    fastIO();
    cin >> n;
    if(n<1 || n>1000000) exit(0);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    cin >> m;
    for(int i=0; i<m; i++) 
    {
        cin >> target;
        binary_search(arr, target, 0, n-1);
    }
    cout << "\n";
    return 0;
}