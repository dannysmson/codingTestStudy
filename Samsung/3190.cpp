#include <bits/stdc++.h>
using namespace std;

// 삼성전자 코딩테스트 기출문제
// 뱀 (자료구조, 구현 Alg.)
// https://www.acmicpc.net/problem/3190
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int N, K, L, board[101][101], ret;
int X;
char ch;
vector<pair<int,char>> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void go(int y, int x)
{
    queue<pair<int,int>> que;
    int dir = 0, pos = 0;
    int t = v[pos].first;
    char turn = v[pos].second;
    board[y][x] = 2;
    que.push(make_pair(y, x));
    while(1)
    {
        ret++;
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || ny >= N || nx < 0 || nx >= N) return;      // 벽에 충돌했을 때
        if(board[ny][nx] == 2) return;     // 자신의 몸에 충돌했을 때
        if(board[ny][nx] == 0)      // 이동한 곳에 사과가 없을 때 꼬리 부분 비우기
        {
            int tailY, tailX;
            if(que.size())
            {
                tie(tailY, tailX) = que.front(); que.pop();
                board[tailY][tailX] = 0;
            }
        }
        que.push(make_pair(ny,nx));    // 이동한 곳에 뱀 마킹
        board[ny][nx] = 2;
        y = ny; x = nx;
        if(ret == t)    // 게임 시간이 방향 전환 정보 시간과 비교하여
        {
            if(turn == 'D') dir = (dir + 1) % 4;
            else dir = (dir + 3) % 4;
            pos++;
            t = v[pos].first;
            turn = v[pos].second;
        }
    }
}
int main()
{
    cin >> N >> K;
    if(N<2 || N>100 || K<0 || K>100) exit(0);

    // 사과 위치 마킹(1)
    for(int i=0; i<K; i++)
    {
        int appleY, appleX;
        cin >> appleY >> appleX;
        if(appleY < 1 || appleY > N || appleX < 1 || appleX > N) exit(0);
        board[appleY-1][appleX-1] = 1;
    }

    // 뱀의 방향 변환 횟수 L
    cin >> L;
    if(L<1 || L>100) exit(0);
    for(int i=0; i<L; i++)
    {
        cin >> X >> ch;
        v.push_back(make_pair(X, ch));
    }

    go(0, 0);
    cout << ret << "\n";
    return 0;
}