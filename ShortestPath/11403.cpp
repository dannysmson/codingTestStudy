#include <bits/stdc++.h>
using namespace std;

// 경로 찾기(실버 1 - Floyd Warshall Alg.)
// https://www.acmicpc.net/problem/11403
int n, arr[101][101];
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
    if(n<1 || n>100) exit(0);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if((arr[i][k] + arr[k][j]) > 1)
                {
                    arr[i][j] = 1;
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}