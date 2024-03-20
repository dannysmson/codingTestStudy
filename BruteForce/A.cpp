#include <bits/stdc++.h>
using namespace std;
// 왕실의 나이트 (Brute Force Alg.)
// 시간 제한: 1초, 메모리 제한: 128MB
// 8X8 좌표평면에서 나이트의 위치가 주어졌을 때 이동할 수 있는 경우의 수 출력
// 행 위치는 1부터 8로 표현, 열 위치는 a 부터 h로 표현

const int dy[8] = {-2, -2, -1, 1, 2, 2, 1, -1}, dx[8] = {1, -1, 2, 2, 1, -1, -2, -2};
int y, x, ret;
string str;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void checkIO(int y, int x)
{
    if(y < 0 || y >= 8 || x < 0 || x >= 8) exit(0);
    return;
}
int main()
{
    fastIO();
    cin >> str;
    x = (int)(str[0] - 'a');
    y = (int)(str[1] - '0') - 1;
    checkIO(y, x);
    for(int i=0; i<8; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= 8 || nx < 0 || nx >= 8) continue;
        ret++;
    }
    cout << ret << "\n";
    return 0;
}