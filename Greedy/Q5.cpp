#include <bits/stdc++.h>
using namespace std;

// 볼링공 고르기(Combination Alg.)
// 시간 제한: 1초, 메모리 제한: 128MB
// 볼링공 N개, 같은 무게 공이 여러 개 존재가능하지만 서로 다른 공으로 간주
// 볼링공의 무게는 1부터 M까지, A, B 두 사람이 서로 무게가 다른 볼링공을 고르려고 함
int n, m, arr[1001], ret;
vector<int> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void combi(int start, vector<int> &v)
{
    if(v.size() == 2)
    {
        if(v[0] != v[1]) ret++;
        return;
    }
    for(int i=start+1; i<n; i++)
    {
        v.push_back(arr[i]);
        combi(i, v);
        v.pop_back();
    }
    return;
}
int main()
{
    fastIO();
    cin >> n >> m;
    if(n<1 || n>1000 || m < 1 || m > 10) exit(0);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        if(arr[i] < 1 || arr[i] > m) exit(0);
    }
    combi(-1, v);
    cout << ret << "\n";
    return 0;
}