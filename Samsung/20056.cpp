#include <bits/stdc++.h>
using namespace std;

// 삼성전자 코딩테스트 기출문제
// 마법사 상어와 파이어볼 (구현 Alg.)
// https://www.acmicpc.net/problem/20056
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, k, ret;
int y, x, mass, speed, dir;
struct fireBall
{
    int y, x, mass, speed, dir;
};
vector<fireBall> arr[51][51];
vector<fireBall> fireBalls;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void move()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) arr[i][j].clear();
    }

    // 모든 파이어볼 이동
    for(int i=0; i<fireBalls.size(); i++)
    {
        int ny = fireBalls[i].y, nx = fireBalls[i].x;
        int m = fireBalls[i].mass, s = fireBalls[i].speed, d = fireBalls[i].dir;
        for(int j=0; j<s; j++)
        {
            ny += dy[d];
            nx += dx[d];
            if(ny < 1) ny = n;
            if(nx < 1) nx = n;
            if(ny > n) ny = 1;
            if(nx > n) nx = 1;
        }
        arr[ny][nx].push_back({ny,nx,m,s,d});
    }
    return;
}
void split()
{
    vector<fireBall> tmp;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int mSum = 0, sSum = 0;
            bool isOdd = false, isEven = false;
            if(arr[i][j].size() == 1)
            {
                tmp.push_back(arr[i][j][0]);
            } else if(arr[i][j].size() > 1)
            {
                for(int k=0; k < arr[i][j].size(); k++)
                {
                    mSum += arr[i][j][k].mass;
                    sSum += arr[i][j][k].speed;
                    if(arr[i][j][k].dir % 2 == 0)
                    {
                        isEven = true;
                    } else isOdd = true;
                }
                mSum /= 5;
                sSum /= arr[i][j].size();

                // 질량이 0인경우
                if(mSum == 0) continue;

                // 모두 홀수이거나 짝수인 경우 판별
                if(isEven ^ isOdd)
                {
                    tmp.push_back({i,j,mSum,sSum,0});
                    tmp.push_back({i,j,mSum,sSum,2});
                    tmp.push_back({i,j,mSum,sSum,4});
                    tmp.push_back({i,j,mSum,sSum,6});
                } else 
                {
                    tmp.push_back({i,j,mSum,sSum,1});
                    tmp.push_back({i,j,mSum,sSum,3});
                    tmp.push_back({i,j,mSum,sSum,5});
                    tmp.push_back({i,j,mSum,sSum,7});
                }
            }
        }
    }
    fireBalls = tmp;
    return;
}
int main()
{
    fastIO();
    cin >> n >> m >> k;
    for(int i=0; i<m; i++)
    {
        cin >> y >> x >> mass >> speed >> dir;
        fireBalls.push_back({y,x,mass,speed,dir});
    }
    for(int i=0; i<k; i++)
    {
        move();
        split();
    }
    for(fireBall it : fireBalls)
    {
        ret += it.mass;
    }
    cout << ret << "\n";
    return 0;
}