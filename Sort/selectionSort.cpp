#include <bits/stdc++.h>
using namespace std;

// 선택정렬 Alg.
// Main Logic: 매 단계마다 가장 작은 데이터를 찾아 앞으로 보냄
// O(N^2) -> 각 단계를 N-1번만큼 반복 * 각 단계에서 최솟값을 찾아야 하는 로직
const int ssize = 10;
int arr[ssize] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};
int main()
{
    for(int i=0; i<ssize-1; i++)
    {
        int min_idx = i;
        for(int j=i+1; j<ssize; j++)
        {
            if(arr[min_idx] > arr[j]) min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
    }

    for(int i=0; i<ssize; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}