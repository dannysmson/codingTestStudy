#include <bits/stdc++.h>
using namespace std;

// 빗물 (골드 5)
// https://www.acmicpc.net/problem/14719
int h, w, num, ret;
vector<int> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int main()
{
    fastIO();
    cin >> h >> w;
    if(h<1 || h>500 || w<1 || w>500) exit(0);
    for(int i=0; i<w; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    
    // 현재 칸 기준, 왼쪽에서 제일 높은 칸과 오른쪽에서 제일 높은 칸 중 더 낮은 칸과 비교
    for(int i=1; i<w-1; i++)
    {
        int leftMax = 0, rightMax = 0;
        for(int j=0; j<i; j++)
        {
            leftMax = max(leftMax, v[j]);
        }
        for(int j=w-1; j>i; j--)
        {
            rightMax = max(rightMax, v[j]);
        }
        ret += max(0, min(leftMax, rightMax) - v[i]);
    }
    cout << ret << "\n";
    return 0;
}