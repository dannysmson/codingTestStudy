#include <bits/stdc++.h>
using namespace std;

// permutation 순열 구현
int arr[3] = {1, 2, 3};
int n = 3, r = 3;
void print()
{
    for(int i=0; i<r; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return;
}
void makePermutation(int n, int r, int depth)
{
    if(depth == r)
    {
        print();
        return;
    }
    for(int i=depth; i<n; i++)
    {
        swap(arr[i], arr[depth]);
        makePermutation(n, r, depth+1);
        swap(arr[i], arr[depth]);
    }
}
int main()
{
    makePermutation(n, r, 0);
    return 0;
}