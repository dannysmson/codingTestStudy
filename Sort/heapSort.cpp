#include <bits/stdc++.h>
using namespace std;

// 힙 정렬 Alg.
// Main Logic: 오름차순 구현 위한 최대 힙 구현 (배열 사용)
// 배열의 인덱스 상 루트 노드를 0이 아닌 1로 두고, 왼쪽 자식: 부모 * 2, 오른쪽 자식: 부모 * 2 + 1
// 부모의 키 값이 항상 자식의 키 값보다 큰 최대힙을 구현
// 최대힙의 루트노드에는 항상 제일 큰 값이 존재하므로, 루트노드와 마지막 노드를 swap 시킨 후 루트노드부터 downHeap을 하며 다시 최대힙 생성
// 시간 복잡도: O(nlogn)
int arr[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};
vector<int> v;
void upHeap()
{
    for(int i=10; i>1; i--)
    {
        int child = i, parent = i / 2;
        while(parent != 0 && v[child] > v[parent])
        {
            swap(v[child], v[parent]);
            child = parent;
            parent = child / 2;
        }
    }
    return;
}
void downHeap(int i, int last)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    if(left > last) return;
    int greater = left;
    if(right <= last)
    {
        if(v[right] > v[greater]) greater = right;
    }
    if(v[i] >= v[greater]) return;
    swap(v[i], v[greater]);
    downHeap(greater, last);
    return;
}
void buildHeap()
{
    v.push_back(0);
    for(int i=0; i<10; i++) v.push_back(arr[i]);
    upHeap();
}
void heapSort()
{
    buildHeap();
    for(int i=10; i>1; i--)
    {
        swap(v[1], v[i]);
        downHeap(1, i-1);
    }
}
int main()
{
    heapSort();
    for(int i=1; i<=10; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}