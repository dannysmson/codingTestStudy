#include <bits/stdc++.h>
using namespace std;

// 퀵정렬 Alg.
// Main Logic: 기준 데이터 Pivot을 설정한 후 Pivot을 기준 왼쪽은 Pivot보다 작은 수, 오른쪽은 큰 수를 배치하도록 하는 방법
// 분할정복 알고리즘이며, 아래 코드는 제자리 정렬 알고리즘 코드이다. (추가적인 메모리를 사용하지 않음)
// 불안정정렬 (동일한 원소에 대한 우선순위가 유지되지 않음)
// 시간복잡도: 평균 O(NlogN), 최악 O(N^2)
const int ssize = 10;
int arr[ssize] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};
void inPlacePartition(int l, int r)
{
    if(l >= r) return;
    int pivot = arr[l];
    swap(arr[l], arr[r]);
    int i = l, j = r - 1;
    while(i<=j)
    {
        while(i<=j && arr[i] <= pivot)
        {
            i = i + 1;
        }
        while(j>=i && arr[j] >= pivot)
        {
            j = j - 1;
        }
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[r]);
    pivot = i;
    inPlacePartition(l, pivot-1);
    inPlacePartition(pivot+1, r);
    return;
}
int main()
{
    inPlacePartition(0, ssize - 1);
    for(int i=0; i<ssize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}