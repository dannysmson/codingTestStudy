#include <bits/stdc++.h>
using namespace std;

// 삽입정렬 Alg.
// Main Logic: 데이터가 들어갈 적절한 위치를 찾아 삽입
// 최악의 경우: O(N^2), 최선의 경우: O(N) 
// 배열의 요소들이 대부분 정렬되어 있을 때 굉장히 효율적
const int ssize = 10;
int arr[ssize] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8}, i, j;
int main()
{
    for(i=1; i<ssize; i++)
    {
        int key = arr[i];
        for(j=i-1; j>=0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }

    for(i=0; i<ssize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}