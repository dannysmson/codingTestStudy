#include <bits/stdc++.h>
using namespace std;

// 9205 맥주 마시면서 걸어가기
int t, n;
struct point {
    int x, y;
};
point store[101], home, dest;
int visited[101];
void bfs()
{
    queue<point> que;
    que.push(home);
    while(que.size())
    {
        int y = que.front().y, x = que.front().x;
        que.pop();

        // 맥주 20개 -> 20 * 50 = 1000
        if(abs(y - dest.y) + abs(x - dest.x) <= 1000)
        {
            cout << "happy" << "\n";
            return;
        }

        for(int i=0; i<n; i++)
        {
            if(visited[i]) continue;
            // 맥주 20개로 목적지는 못가지만 편의점은 갈 수 있는 경우
            if(abs(y - store[i].y) + abs(x - store[i].x) <= 1000)
            {
                que.push(store[i]);
                visited[i] = 1;
            }
        }
    }
    cout << "sad" << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    
    while(t--)
    {
        memset(visited, 0, sizeof(visited));
        cin >> n;
        cin >> home.x >> home.y;
        for (int i=0; i < n; i++) {
            cin >> store[i].x >> store[i].y;
        }
        cin >> dest.x >> dest.y;
        bfs();
    }

    return 0;
}