#include <bits/stdc++.h>
using namespace std;

// 삼성전자 코딩테스트 기출문제
// 드래곤커브 (구현 Alg.)
// https://www.acmicpc.net/problem/15685
int n, x, y, d, g, ret;
int board[104][104];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// x, y좌표가 이 문제에선 반대지만, 뒤집지 않고 반대로 두고 그냥 풀었음
void dragonCurve(int x, int y, int d, int g)
{
    // 처음 주어진 좌표에서 0세대 까지만 먼저 진행
    board[x][y] = 1;
    vector<int> v;
    int nx = x + dx[d];
    int ny = y + dy[d];
    board[nx][ny] = 1;
    // 벡터에는 방향 정보만을 담고, 끝점만 관리하면서 진행
    // 방향: 이전 좌표에서 이동한 방향의 반대 방향 정보를 담음
    // 시계 방향으로 회전하기 위함!
    v.push_back((d+2)%4);
    for(int i=1; i<=g; i++)
    {
        int vector_size = v.size();
        for(int j=vector_size-1; j>=0; j--)
        {
            int d = v[j];
            d = (d+3)%4;
            nx += dx[d];
            ny += dy[d];
            board[nx][ny] = 1;
            v.push_back((d+2)%4);
        }
    }
    return;
}
// 1x1 사각형 체크
void check()
{
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            if(board[i][j] + board[i+1][j] + board[i][j+1] + board[i+1][j+1] == 4) ret++;
        }
    }
    return;
}
int main()
{
    fastIO();
    cin >> n;
    if(n<1 || n>20) exit(0);
    for(int i=0; i<n; i++)
    {
        cin >> x >> y >> d >> g;
        if(x<0 || x>100 || y<0 || y>100 || d<0 || d>3 || g<0 || g>10) exit(0);
        dragonCurve(x, y, d, g);
    }
    check();
    cout << ret << "\n";
    return 0;
}