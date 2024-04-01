#include <bits/stdc++.h>
using namespace std;

// 2020 카카오 신입 공채 
// 문자열 압축 (Brute Force Alg.)
// https://programmers.co.kr/learn/courses/30/lessons/60057
// (문제는 기본 코드가 제공되므로 상기 링크를 통해서 문제를 풀어야 함)
int solution(string s) {
    int answer = s.size();
    for(int i=1; i<=s.size()/2; i++) {
        string compressed = "";
        string prev = s.substr(0, i);
        int cnt = 1;
        for(int j=i; j<s.size(); j+=i) {
            if(prev == s.substr(j, i)) cnt++;
            else {
                if(cnt > 1) compressed += to_string(cnt) + prev;
                else compressed += prev;
                prev = s.substr(j, i);
                cnt = 1;
            }
        }
        if(cnt > 1) compressed += to_string(cnt) + prev;
        else compressed += prev;
        answer = min(answer, (int)compressed.size());
    }
    return answer;
}
int main()
{
    string s;
    cin >> s;
    cout << solution(s) << "\n";
    return 0;
}