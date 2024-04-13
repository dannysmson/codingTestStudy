#include <bits/stdc++.h>
using namespace std;

// 삼성전자 코딩테스트 기출문제
// 마법사 상어와 토네이도 (Alg.)
// https://www.acmicpc.net/problem/20057
const int dy[] = {0, 1, 0, -1};
const int dx[] = {-1, 0, 1, 0};
int ydy[4][10] = {{-1,1,-1,1,-1,1,-2,2,0,0}, {-1,-1,0,0,1,1,0,0,2,1}, {-1,1,-1,1,-1,1,-2,2,0,0}, {1,1,0,0,-1,-1,0,0,-2,-1}};
int xdx[4][10] = {{1,1,0,0,-1,-1,0,0,-2,-1}, {-1,1,-1,1,-1,1,-2,2,0,0}, {-1,-1,0,0,1,1,0,0,2,1}, {-1,1,-1,1,-1,1,-2,2,0,0}};
int percent[9] = {1,1,7,7,10,10,2,2,5};
int n, arr[500][500], visited[500][500], y, x, ret;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void spread(int y, int x, int dir)
{
    int sandAmount = arr[y][x];
    int tmp = sandAmount;
    for(int i=0; i<9; i++)
    {
        int ny = y + ydy[dir][i];
        int nx = x + xdx[dir][i];
        int per = percent[i];
        int amount = (tmp * per) / 100;
        if(ny < 0 || ny >= n || nx < 0 || nx >=n) ret += amount;
        else arr[ny][nx] += amount;
        sandAmount -= amount;
    }
    int ny = y+ydy[dir][9];
    int nx = x+xdx[dir][9];
    if(ny<0 || ny>=n || nx<0 || nx>=n) ret += sandAmount;
    else arr[ny][nx] += sandAmount;
    arr[y][x] = 0;
    return;
}
void go(int y, int x, int dir)
{
    visited[y][x] = 1;
    while(1)
    {
        int ny = y + dy[(dir+1)%4];
        int nx = x + dx[(dir+1)%4];
        if(visited[ny][nx]) 
        {
            ny = y + dy[dir];
            nx = x + dx[dir];
        } else
        {
            dir = (dir+1)%4;
        }
        visited[ny][nx] = 1;
        spread(ny, nx, dir);
        if(ny==0 && nx ==0) return;
        y = ny; x = nx;
    }
}
int main()
{
    fastIO();
    cin >> n;
    if(n<3 || n>499) exit(0);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }
    y = x = n/2;
    go(y, x, 3);
    cout << ret << "\n";
    return 0;
}