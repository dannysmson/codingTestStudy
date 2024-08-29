#include <bits/stdc++.h>
using namespace std;

// 보물 (실버 4)
int A[101], B[101], n, ret;
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
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> B[i];
    }
    sort(A, A+n);
    sort(B, B+n, greater<int>());
    for(int i=0; i<n; i++)
    {
        ret += A[i]*B[i];
    }
    cout << ret << "\n";
    return 0;
}