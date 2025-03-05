#include <bits/stdc++.h>
using namespace std;

// 압축
string str;
int ret;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input()
{
    cin >> str;
    return;
}
void solution()
{
    input();
    stack<int> st;
    for(int i=0; i<str.size(); i++){
        // '('가 나오면 스택에 -1 push
        if(str[i]=='(') st.push(-1);
        // 문자 형식의 숫자가 나오면 다음 문자가 '('인지 확인 후 push
        else if(isalnum(str[i]))
        {
            if(i < str.size()-1 && str[i+1] == '(') st.push(str[i] - '0');  // 다음 문자가 '('이면 해당 숫자 push
            else st.push(1);    // 아니면 그냥 1 push (문자열 길이를 나타내는 값)
        }
        else
        {
            int len=0;
            while(st.top() != -1) {
                len += st.top();
                st.pop();
            }
            // -1 즉 '('이 나오기 전까지 pop하면서 더해주므로 한번 더 pop
            st.pop();
            len *= st.top(); st.pop();
            st.push(len);
        }
    }
    while(!st.empty()){
        ret += st.top();
        st.pop();
    }
    cout << ret << "\n";
    return;
}
int main()
{
    fastIO();
    solution();
    return 0;
}