#include <bits/stdc++.h>
using namespace std;

// 2024 삼성전자 코딩테스트 오후 기출문제 1번

// nxm 크기의 행성에 k개의 우주선 착륙시키기 (1x1크기 5개로 이루어진 십자가 모양 우주선)
// 우주선은 1x1 크기 5개의 블록으로 이루어진 십자가 모양이며, {0,1,2,3} => {북,동,남,서} 우주선의 출구 위치 존재
// 우주선이 행성의 맨 위에서 떨어지는 방법은 3가지 (우선순위 존재) 
// 행성 벽에 닿거나 다른 우주선이 쌓여있는 경우 이동 불가
// 1. 그냥 아래로 떨어진다 (moveDown)
// 2. 1번이 안될 경우, 반시계 방향으로 90도 회전하여 내려가기
// 3. 1,2번이 안될 경우, 시계 방향으로 90도 회전하여 내려가기
// 1,2,3번 다 안될 경우, 멈춤 (멈췄을 때, 우주선의 일부가 행성 밖에 존재할 경우 행성 내 쌓여있는 모든 우주선 초기화)
// 멈춘 후, 각 우주선의 정 중앙에는 로봇이 존재하는데 로봇이 탐사할 수 있는 Logic
// 같은 우주선 내에서는 상하좌우 자유롭게 이동가능
// 다른 우주선으로 이동하기 위해서는 현재 우주선의 출구에 맞닿은 다른 우주선이 존재해야 함.
// 가장 깊게 내려갈 수 있는 y좌표를 구해, 각 우주선이 탐사할 수 있는 최대 깊이를 모두 더한 결과값 출력

// 예제 입력
// 1
// 9 7 3
// 2 0
// 2 1
// 이렇게했을 때 확인해보기
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int t, n, m, k, arr[74][74], checkExit[74][74], visited[74][74];
int col, dir, ret, max_y;
void print();
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// 문제에선 70x70이 최대이지만, 0행부터 비교해야 하므로, 우주선 크기만큼 초기 y좌표를 3만큼 증가시켜 초기 우주선 위치를 초기화
// 각 우주선을 구분하기 위해 k값으로 초기화
void initPlane(int col, int dir, int k)
{
    for(int i=0; i<3; i++)
    {
        for(int j=col-1; j<=col+1; j++)
        {
            if((i==0 && j==col-1) || (i==0 && j==col+1) || (i==2 && j==col-1) || (i==2 && j==col+1)) continue;
            arr[i][j] = k;            
        }
    }
    return;
}
// 아래로 움직일 수 있는지 확인
bool checkDown(int y, int x)
{
    if(arr[y][x] || arr[y-1][x-1] || arr[y-1][x+1]) return false;
    return true;
}
void moveDown(int y, int x)
{
    for(int i=y; i>y-3; i--)
    {
        for(int j=x-1; j<=x+1; j++)
        {
            if((i==y && j==x-1) || (i==y && j==x+1) || (i==y-2 && j==x-1) || (i==y-2 && j==x+1)) continue;
            arr[i][j] = arr[i-1][j];
            arr[i-1][j] = 0;      
        }
    }
}
// 반시계 회전
void rotateLeft(int y, int x)
{
    int ny = y - 3, nx = x - 1;
    int tmp[3][3];
    memset(tmp, 0, sizeof(tmp));
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if((i==0 && j==0) || (i==0 && j==2) || (i==2 && j==0) || (i==2 && j==2)) continue;
            tmp[i][j] = arr[j+ny][3-i-1+nx];
        }
    }
    for(int i=ny; i<ny+3; i++)
    {
        for(int j=nx; j<nx+3; j++)
        {
            if((i==ny && j==nx) || (i==ny && j==nx+2) || (i==ny+2 && j==nx) || (i==ny+2 && j==nx+2)) continue;
            arr[i][j] = tmp[i-ny][j-nx];
        }
    }
    return;
}
// 시계 회전
void rotateRight(int y, int x)
{
    int ny = y - 3, nx = x - 1;
    int tmp[3][3];
    memset(tmp, 0, sizeof(tmp));
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if((i==0 && j==0) || (i==0 && j==2) || (i==2 && j==0) || (i==2 && j==2)) continue;
            tmp[i][j] = arr[3-j-1+ny][i+nx];
        }
    }
    for(int i=ny; i<ny+3; i++)
    {
        for(int j=nx; j<nx+3; j++)
        {
            if((i==ny && j==nx) || (i==ny && j==nx+2) || (i==ny+2 && j==nx) || (i==ny+2 && j==nx+2)) continue;
            arr[i][j] = tmp[i-ny][j-nx];
        }
    }
    return;
}
// 반시계 회전 후, 왼쪽 이동 + 아래 이동
int moveLeft(int y, int x)
{
    rotateLeft(y, x);
    for(int i=y-3; i<y; i++)
    {
        for(int j=x-1; j<=x+1; j++)
        {
            if((i==y-3 && j==x-1) || (i==y-3 && j==x+1) || (i==y-1 && j==x-1) || (i==y-1 && j==x+1)) continue;
            arr[i][j-1] = arr[i][j];
            arr[i][j] = 0;
        }
    }
    x = x - 1;
    moveDown(y, x);
    return x;
}
// 시계 회전 후, 오른쪽 이동 + 아래 이동
int moveRight(int y, int x)
{
    rotateRight(y, x);
    for(int i=y-3; i<y; i++)
    {
        for(int j=x+1; j>=x-1; j--)
        {
            if((i==y-3 && j==x-1) || (i==y-3 && j==x+1) || (i==y-1 && j==x-1) || (i==y-1 && j==x+1)) continue;
            arr[i][j+1] = arr[i][j];
            arr[i][j] = 0;
        }
    }
    x = x + 1;
    moveDown(y, x);
    return x;
}
bool checkLeft(int y, int x)
{
    if(x < 2) return false;
    if(arr[y][x-1] || arr[y-1][x-1] || arr[y-1][x-2] || arr[y-2][x-2] || arr[y-3][x-1]) return false;
    return true;
}
bool checkRight(int y, int x)
{
    if(x >= m-2) return false;
    if(arr[y][x+1] || arr[y-1][x+1] || arr[y-1][x+2] || arr[y-2][x+2] || arr[y-3][x+1]) return false;
    return true;
}
// 로봇 탐사 확인 로직
void bfs(int y, int x)
{
    queue<pair<int,int>> que;
    visited[y][x] = 1;
    que.push(make_pair(y,x));
    while(que.size())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
        max_y = max(max_y, y);
        for(int i=0; i<4; i++)
        {
            int ny = y+dy[i];
            int nx = x+dx[i];
            // 벽에 닿거나, 다른 탐사선이 있거나, 아무 탐사선이 없는 경우, 이미 방문한 위치인 경우
            if(ny<3 || ny>=n+3 || nx<0 || nx>=m || visited[ny][nx] || arr[ny][nx] == 0) continue;
            // 다른 탐사선으로 이동했는데, 출구로부터 이동하지 않은 경우
            if(arr[y][x] != arr[ny][nx] && checkExit[y][x] != -1) continue;
            que.push(make_pair(ny,nx));
            visited[ny][nx] = 1;
        }
    }
    return;
}
// 출구 마킹
void markExit(int y, int x, int dir)
{
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    checkExit[ny][nx] = -1;
    return;
}
void go(int col, int dir)
{
    int row = 3;
    max_y = 0;
    memset(visited, 0, sizeof(visited));
    while(row < n+3)
    {
        if(checkDown(row, col))
        {
            moveDown(row, col);
        } else if(checkLeft(row, col))
        {
            col = moveLeft(row, col);
            dir = (dir + 3) % 4;
        } else if(checkRight(row, col))
        {
            col = moveRight(row, col);
            dir = (dir + 1) % 4;
        } else
        {
            if(row < 5)
            {
                memset(arr, 0, sizeof(arr));
                memset(checkExit, 0, sizeof(checkExit));
                return;
            }
            break;
        }
        row++;
    }
    row = row-2;
    markExit(row, col, dir);
    bfs(row, col);
    // y좌표나 x좌표를 (0,0) 시작인지 (1,1) 시작인지에 따라 +1 달라짐
    ret += (max_y-3+1);
    return;
}
int main()
{
    fastIO();
    cin >> t;
    if(t>1000) exit(0);

    while(t--)
    {
        ret = 0;
        cin >> n >> m >> k;
        for(int i=1; i<=k; i++)
        {
            cin >> col >> dir;
            initPlane(col, dir, i);
            go(col, dir);
        }
        cout << ret << "\n";
    }
    return 0;
}