#include <bits/stdc++.h>
using namespace std;

// 1339 단어 수학
int n;
vector<string> v;
vector<int> alpha(26);
int ret;
string str;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> str;
        v.push_back(str);
    }

    for(int i=0; i<n; i++)
    {
        int len = v[i].size();
        for(int j=0; j<len; j++)
        {
            alpha[v[i][j] - 'A'] += pow(10, len-j-1);
        }
    }
    sort(alpha.begin(), alpha.end(), greater<int>());
    for(int i=0; i<10; i++)
    {
        ret += alpha[i] * (9-i);
    }
    cout << ret << "\n";
    return 0;
}