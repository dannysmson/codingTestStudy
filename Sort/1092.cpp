#include <bits/stdc++.h>
using namespace std;

// 배 (골드 5. Sort Alg.)
// https://www.acmicpc.net/problem/1092
int n, m, num, ret, idx;
vector<int> crane, box;
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
    if(n<1 || n>50) exit(0);
    for(int i=0; i<n; i++)
    {
        cin >> num;
        crane.push_back(num);
    }
    cin >> m;
    if(m<1 || m>10000) exit(0);
    for(int i=0; i<m; i++)
    {
        cin >> num;
        box.push_back(num);
    }
    sort(crane.begin(), crane.end(), greater<int>());
    sort(box.begin(), box.end(), greater<int>());
    
    if(crane[0] < box[0]) 
    {
        cout << -1 << "\n";
        exit(0);
    }
    while(!box.empty())
    {
        ret++;
        for(int i=0; i<crane.size(); i++)
        {
            for(int j=0; j<box.size(); j++)
            {
                if(crane[i] >= box[j])
                {
                    box.erase(box.begin()+j);
                    break;
                }
            }
        }
    }
    cout << ret << "\n";
    return 0;
}

// 6 8 9
// 2 2 4 5 7