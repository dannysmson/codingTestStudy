#include <bits/stdc++.h>
using namespace std;

// 이모티콘
// DFS&BFS
#define _MAX 1000
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int s, ret;
bool visited[_MAX+1][_MAX+1];   // [화면 이모티콘 갯수][클립보드 이모티콘 갯수]
queue<pair<pair<int,int>, int>> que;

// 입력
void input()
{
    cin >> s;
    if(s < 2 || s > 1000) exit(0); // 입력 처리
    return;
}
// bfs 코드
void bfs()
{
    visited[1][0] = true;
    que.push(make_pair(make_pair(1, 0), 0));
    while(!que.empty())
    {
        int display = que.front().first.first;
        int clip = que.front().first.second;
        int t = que.front().second;
        que.pop();

        if(display == s) 
        {
            cout << t << "\n";
            return;
        }
        if(display > 0 && display <= 1000)
        {
            // 1번 조건 (화면에 이모티콘 갯수 -> 클립보드에 복사)
            if(visited[display][display] == false)
            {
                visited[display][display] = true;
                que.push(make_pair(make_pair(display, display), t + 1));
            }
            if(visited[display - 1][clip] == false)
            {
                visited[display - 1][clip] = true;
                que.push(make_pair(make_pair(display - 1, clip), t + 1));
            }
        }
        if(clip > 0 && display + clip <= _MAX)
        {
            if(visited[display + clip][clip] == false)
            {
                visited[display + clip][clip] = true;
                que.push(make_pair(make_pair(display + clip, clip), t + 1));
            }
        }
    }
    return;
}
void solution()
{
    input();
    bfs();
    return;
}
int main()
{
    fastIO();
    solution();
    return 0;
}