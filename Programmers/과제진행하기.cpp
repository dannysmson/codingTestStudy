#include <bits/stdc++.h>
using namespace std;

// 과제 진행하기
string str;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
bool comp(vector<string>& a, vector<string>& b)
{
    return a[1] < b[1];
}
int convertToMinute(string time)
{
    const int hour = stoi(time.substr(0, 2)) * 60;
    const int min = stoi(time.substr(3));
    return hour + min;
}
vector<string> solution(vector<vector<string>> plans)
{
    int i;
    vector<string> answer;
    stack<string> stk;
    map<string, int> mp;
    // 시작 시간 순서로 정렬
    sort(plans.begin(), plans.end(), comp);
    int prevTime = convertToMinute(plans[0][1]);
    mp[plans[0][0]] = stoi(plans[0][2]);
    for(i=1; i<plans.size(); i++)
    {
        mp[plans[i][0]] = stoi(plans[i][2]);
        int curTime = convertToMinute(plans[i][1]);
        if(prevTime + stoi(plans[i-1][2]) <= curTime)
        {
            answer.push_back(plans[i-1][0]);
            mp[plans[i-1][0]] = 0;
            prevTime += stoi(plans[i-1][2]);
            while(!stk.empty()) 
            {
                int remainTime = mp[stk.top()];
                if(prevTime + remainTime <= curTime)
                {
                    answer.push_back(stk.top());
                    mp[stk.top()] = 0;
                    prevTime += remainTime;
                    stk.pop();
                } else 
                {
                    mp[stk.top()] -= (curTime - prevTime);
                    break;
                }
            }
        } else 
        {
            mp[plans[i-1][0]] -= (curTime - prevTime);
            stk.push(plans[i-1][0]);
        }
        prevTime = curTime;
    }
    answer.push_back(plans[i-1][0]);
    while(!stk.empty())
    {
        answer.push_back(stk.top());
        stk.pop();
    }
    return answer;
}
int main()
{
    fastIO();
    vector<vector<string>> plans;
    // Programmers 특징 상, 함수만 구현하면 되므로 입력 갯수가 지정되어 있지 않음
    for(int i=0; i<3; i++)
    {
        vector<string> tmp;
        for(int j=0; j<3; j++)
        {
            cin >> str;
            tmp.push_back(str);
        }
        plans.push_back(tmp);
    }
    vector<string> answer = solution(plans);
    for(string name : answer) 
    {
        cout << name << " ";
    }
    cout << "\n";
    return 0;
}
/*
****문제 설명****
- 과제 계획을 담은 이차원 문자열 배열 [과제이름, 시작시간, 과제 마치는 데 걸리는 시간]
- 과제는 시작하기로 한 시간에 시작
- 새로운 과제를 시작해야 할 시간이면, 진행중이던 과제 일시중지
- 과제를 끝냈는데 일시중지한 과제가 존재하면 이어서 진행
    - 멈춰둔 과제가 여러개일 경우 가장 최근에 중지한 과제부터 진행
    - 과제를 끝낸 시각에 새로 시작해야 하는 과제와 일시중지한 과제가 있다면, 새로 시작해야 하는 과제먼저 진행
- 과제를 종료한 순서대로 이름을 담은 배열 반환
입력 예시
[["korean", "11:40", "30"], ["english", "12:10", "20"], ["math", "12:30", "40"]]
출력 예시
["korean", "english", "math"]

****문제 분석****
1. 이차원 배열이 과제 시작시간으로 정렬되어 있지 않을 수 있으므로 과제 시작시간에 맞춰 정렬
2. 과제별로 playtime이 얼마나 남았는지 저장할 만한 자료구조 필요 (map ?)
3. 일시중지한 과제를 관리할 자료구조 필요 (stack - "후입선출", 가장 최근에 일시중지한 과제먼저 진행해야 하기 때문)
4. aa:bb 형식으로 이루어진 시간 계산을 어떻게 할 것인지에 대한 고민도 필요
*/