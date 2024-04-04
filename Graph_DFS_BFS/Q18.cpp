#include <bits/stdc++.h>
using namespace std;

// 괄호 변환 (재귀함수 Alg.)
// https://programmers.co.kr/learn/courses/30/lessons/60058

/*1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
  3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
  4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
  4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
  4-3. ')'를 다시 붙입니다. 
  4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
  4-5. 생성된 문자열을 반환합니다.*/
string str;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
bool check(string str)
{
    stack<char> st;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == '(') st.push(str[i]);
        else 
        {
            if(st.size()) st.pop();
        }
    }
    if(st.size()) return false;
    return true;
}
string rotate(string str)
{
    string ans = "";
    for(int i=1; i<str.size()-1; i++)
    {
        if(str[i] == '(') ans += ')';
        else ans += '(';
    }
    return ans;
}
string solution(string str)
{
    string ans = "";
    string u = "", v="";
    if(str.size() == 0) return str;
    int cnt1 = 0, cnt2 = 0, idx = 0;
    for(idx=0; idx<str.size(); idx++)
    {
        if(str[idx] == '(') cnt1++;
        else cnt2++;
        if(cnt1 == cnt2) break;
    }
    // u, v 문자열 분할 (u는 균형문자열)
    u = str.substr(0, idx+1);
    v = str.substr(idx+1);

    // u가 올바른 괄호 문자열일 때, v에 대해 실행
    if(check(u))
    {
        ans += u + solution(v);
    } else  // u가 올바르지 않은 괄호 문자열일 때, 4번과정 실행
    {
        ans += ('(' + solution(v) + ')' + rotate(u));
    }
    return ans;
}
int main()
{
    fastIO();
    cin >> str;
    cout << solution(str) << "\n";
    return 0;
}