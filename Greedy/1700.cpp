#include <bits/stdc++.h>
using namespace std;

// 멀티탭 스케줄링 (골드 1, Greedy Alg.)
// https://www.acmicpc.net/problem/1700
int n, k, ret;
vector<int> v;
vector<int> hole;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void solution()
{
    int i, idx;
    // 콘센트가 다 사용중일 때까지 확인
    for(i=0; i<k; i++)
    {
        auto it = find(hole.begin(), hole.end(), v[i]);
        if(it == hole.end())
        {
            hole.push_back(v[i]);
        } else continue;
        if(hole.size() == n) break;
    }

    // 콘센트가 다 사용중일 때, 그 다음부터 사용할 전기용품의 번호 확인
    for(idx = i+1; idx<k; idx++)
    {
        auto it = find(hole.begin(), hole.end(), v[idx]);
        if(it != hole.end()) continue;
        else
        {
            // 이미 사용중일 때, 제일 늦게 사용할 가전제품의 번호를 찾기
            int pos = -1;
            int swapIdx = -1;
            for(int j=0; j<n; j++)
            {
                int tmp = 0;
                for(int m=idx+1; m<k; m++)
                {
                    if(hole[j] == v[m]) break;
                    tmp++;
                }
                if(tmp > swapIdx)
                {
                    swapIdx = tmp;
                    pos = j;
                }
            }
            hole[pos] = v[idx];
            ret++;
        }
    }
    return;
}
int main()
{
    // 입출력 처리
    fastIO();
    cin >> n >> k;
    if(n<1 || n>100 || k<1 || k>100) exit(0);

    // 입력
    for(int i=0; i<k; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    solution();
    cout << ret << "\n";
    return 0;
}