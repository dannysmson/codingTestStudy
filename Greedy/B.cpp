#include <bits/stdc++.h>
using namespace std;

// 숫자 카드 게임
// Greedy Alg.

// 시간 제한 1초, 메모리 제한 128MB
// N x M 배열의 카드에서 각 행에서 가장 낮은 카드를 뽑아야 함, 낮은 숫자 중 가장 높은 숫자의 카드를 뽑기
// 입력조건: (1 <= N, M <= 100)
int n, m, arr[104][104], ret = -1;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void checkIO(int n, int m)
{
    if(n < 1 || n > 100 || m < 1 || m > 100) exit(0);
    return;
}
int main()
{
    fastIO();
    cin >> n >> m;
    checkIO(n, m);
    for(int i=0; i<n; i++)
    {
        int tmp = 10001;
        for(int j=0; j<m; j++) 
        {
            cin >> arr[i][j];
            tmp = min(tmp, arr[i][j]);
        }
        ret = max(ret, tmp);
    }
    cout << ret << "\n";
    return 0;
}