#include <bits/stdc++.h>
using namespace std;

// 뒤에 있는 큰 수 찾기
// 정수배열 numbers가 주어졌을 때, 배열 각 원소들에 대해 자신보다 뒤에 있는 숫자 중 자신보다 크며 가장 가까이 있는 수를 담아 반환
// 정수 배열 길이 
int N, num;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
vector<int> solution(vector<int> numbers) 
{
    vector<int> answer(numbers.size());
    stack<int> stk;
    for(int i=numbers.size()-1; i>=0; i--)
    {
        while(1)
        {
            if(stk.empty())
            {
                answer[i] = -1;
                break;
            }
            if(numbers[i] < stk.top())
            {
                answer[i] = stk.top();
                break;
            }
            stk.pop();
        }
        stk.push(numbers[i]);
    }
    return answer;
}
int main()
{
    fastIO();
    vector<int> numbers;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> num;
        numbers.push_back(num);
    }
    vector<int> answer = solution(numbers);
    for(int num : answer) 
    {
        cout << num << " ";
    }
    cout << "\n";
    return 0;
}