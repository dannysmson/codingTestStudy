#include <bits/stdc++.h>
using namespace std;

// 마법의 엘레베이터
/*
***문제 분석***
- 엘레베이터 버튼종류: -1, +1, -10, +10, -100, +100 등 절댓값이 10^c (c는 정수)
- 버튼을 누를 시 [현재 층 수 + 버튼 값]으로 이동하지만, 이동할 층 번호가 0보다 작을 시 이동하지 않음
- 버튼 한 번 누를 때 마다 [마법의 돌] 1개를 사용
- 현재 층에서 0층으로 가기위한 최소한의 마법의 돌 갯수 구하기
*/
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int solution(int storey)
{
    int answer = 0;
    while(storey)
    {
        int pos = storey % 10;
        if(pos > 5)
        {
            answer += (10 - pos);
            storey += 10;
        } else if(pos < 5)
        {
            answer += pos;
        } else 
        {
            int tmp = storey / 10;
            if((tmp % 10) >= 5)
            {
                answer += (10 - pos);
                storey += 10;
            } else
            {
                answer += pos;
            }
        }
        storey /= 10;
    }
    return answer;
}
int main()
{
    fastIO();
    // 예제 입출력
    // storey: 16, answer: 6
    // storey: 2554, answer: 16
    cout << solution(16) << "\n";
    cout << solution(2554) << "\n";
    return 0;
}