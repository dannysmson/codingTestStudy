#include <bits/stdc++.h>
using namespace std;

const int n = 3;
const int m = 4;
int cnt = 1;
// 2차원 배열 회전 연습
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void print(vector<vector<int>> v)
{
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}
void rotate_left_90(vector<vector<int>> &arr)
{
    vector<vector<int>> tmp(m, vector<int>(n, 0));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            tmp[i][j] = arr[j][m-i-1];
        }
    }
    arr.resize(m);
    arr[0].resize(n);
    arr = tmp;
    return;
}
void rotate_right_90(vector<vector<int>> &arr)
{
    vector<vector<int>> tmp(m, vector<int>(n, 0));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            tmp[i][j] = arr[n-j-1][i];
        }
    }
    arr.resize(m);
    arr[0].resize(n);
    arr = tmp;
    return;
}
int main()
{
    fastIO();
    vector<vector<int>> v(n, vector<int>(m, 0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            v[i][j] = cnt++;
        }
    }
    print(v);
    cout << "\n";
    /*rotate_left_90(v);
    print(v);*/
    rotate_right_90(v);
    print(v);
    return 0;
}