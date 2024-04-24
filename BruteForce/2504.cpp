#include <bits/stdc++.h>
using namespace std;

// 괄호의 값 (골드 5)
// https://www.acmicpc.net/problem/2504
string str;
int strSize, ret;
stack<char> st;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input()
{
    cin >> str;
    strSize = str.size();
    if(strSize < 1 || strSize > 30) exit(0);
    return;
}
int check(char ch)
{
    if(ch == ')')
    {
        if(!st.empty() && st.top() == '(')
        {
            st.pop();
            return 2;
        } else return 0;
    } else if(ch == ']')
    {
        if(!st.empty() && st.top() == '[')
        {
            st.pop();
            return 3;
        } else return 0;
    }
    return 0;
}
void solution()
{
    int tmp = 1;
    for(int i=0; i<strSize; i++)
    {
        if(str[i] == '(' || str[i] == '[')
        {
            st.push(str[i]);
            if(str[i] == '(') tmp *= 2;
            else tmp *= 3;
        } else 
        {
            if(str[i] == ')')
            {
                if(st.empty() || st.top() != '(')
                {
                    ret = 0;
                    break;
                }
                st.pop();
                if(str[i-1] == '(')
                {
                    ret += tmp;
                    tmp /= 2;
                } else tmp /= 2;
            }
            else if(str[i] == ']')
            {
                if(st.empty() || st.top() != '[')
                {
                    ret = 0;
                    break;
                }
                st.pop();
                if(str[i-1] == '[')
                {
                    ret += tmp;
                    tmp /= 3;
                } else tmp /= 3;
            }
        }
    }
    if(!st.empty()) ret = 0;
    return;
}
int main()
{
    fastIO();
    input();
    solution();
    cout << ret << "\n";
    return 0;
}
