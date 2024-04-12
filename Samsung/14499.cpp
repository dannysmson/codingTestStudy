#include <bits/stdc++.h>
using namespace std;

// 삼성전자 코딩테스트 기출문제
// 주사위 굴리기 (구현 Alg.)
// https://www.acmicpc.net/problem/14499
int n, m, x, y, k, dir;
int arr[21][21], dice[4][3];
const int dy[] = {0, 0, 0, -1, 1};  // x, 동, 서, 북, 남 (순서 -> 방향이 1, 2, 3, 4로 주어지기 때문에 0일때는 이동 안하도록)
const int dx[] = {0, 1, -1, 0, 0};  // x, 동, 서, 북, 남
vector<int> v;
// Main Logic: 주사위 전개도를 4x3 배열로 만들어놓고, 굴리는 방향에 따라 맞게 swap
// - 0 -
// 0 0 0
// - 0 -
// - 0 - 
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void rollEast(int y, int x)
{
    int tmp = dice[3][1];
    dice[3][1] = dice[1][0];
    dice[1][0] = dice[1][1];
    dice[1][1] = dice[1][2];
    dice[1][2] = tmp;
    if(arr[y][x])
    {
        dice[1][1] = arr[y][x];
        arr[y][x] = 0;
    } else {
        arr[y][x] = dice[1][1];
    }
    cout << dice[3][1] << "\n";
    return;
}
void rollWest(int y, int x)
{
    int tmp = dice[3][1];
    dice[3][1] = dice[1][2];
    dice[1][2] = dice[1][1];
    dice[1][1] = dice[1][0];
    dice[1][0] = tmp;
    if(arr[y][x])
    {
        dice[1][1] = arr[y][x];
        arr[y][x] = 0;
    } else {
        arr[y][x] = dice[1][1];
    }
    cout << dice[3][1] << "\n";
    return;
}
void rollNorth(int y, int x)
{
    int tmp = dice[3][1];
    dice[3][1] = dice[2][1];
    dice[2][1] = dice[1][1];
    dice[1][1] = dice[0][1];
    dice[0][1] = tmp;
    if(arr[y][x])
    {
        dice[1][1] = arr[y][x];
        arr[y][x] = 0;
    } else {
        arr[y][x] = dice[1][1];
    }
    cout << dice[3][1] << "\n";
    return;
}
void rollSouth(int y, int x)
{
    int tmp = dice[3][1];
    dice[3][1] = dice[0][1];
    dice[0][1] = dice[1][1];
    dice[1][1] = dice[2][1];
    dice[2][1] = tmp;
    if(arr[y][x])
    {
        dice[1][1] = arr[y][x];
        arr[y][x] = 0;
    } else {
        arr[y][x] = dice[1][1];
    }
    cout << dice[3][1] << "\n";
    return;
}
void go(int y, int x, vector<int> &v)
{
    for(int dir : v)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        // 범위 넘어가려 하면 무시
        // 방향에 따라 맞는 함수 호출
        // 함수는 기본적으로 주사위 전개도에 따름
        switch(dir)
        {
            case 1:
                rollEast(ny, nx);
                break;
            case 2:
                rollWest(ny, nx);
                break;
            case 3:
                rollNorth(ny, nx);
                break;
            case 4:
                rollSouth(ny, nx);
        }
        y = ny; x = nx;
    }
}
int main()
{
    fastIO();
    cin >> n >> m >> x >> y >> k;
    if(n<1 || n>20 || m<1 || m>20 || x<0 || x>=n || y<0 || y>=m || k<1 || k>1000) exit(0);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<k; i++) 
    {
        cin >> dir;
        v.push_back(dir);   
    }
    go(x, y, v);
    return 0;
}