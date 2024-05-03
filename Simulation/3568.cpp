#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
// #include <bits/stdc++.h> 를 지원하지 않는 코테 환경도 많기에 연습용
using namespace std;

// iSharp (실버 3 - Simulation Alg.)
// https://www.acmicpc.net/problem/3568
string str;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while((pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}
void print(vector<string> &vec)
{
    for(int i=1; i<vec.size(); i++)
    {
        cout << vec[0];
        for(int idx=vec[i].size()-1; idx>=0; idx--)
        {
            if(vec[i][idx] == ',' || vec[i][idx] == ';') continue;
            if(vec[i][idx] == '&' || vec[i][idx] == '*') cout << vec[i][idx];
            else if(vec[i][idx] == ']')
            {
                cout << vec[i][idx-1] << vec[i][idx];
                idx--;
            }
            else 
            {
                cout << " ";
                for(int j=0; j<=idx; j++) cout << vec[i][j];
                cout << ";\n";
                break;
            }
        }
    }
    return;
}
int main()
{
    fastIO();
    getline(cin, str);
    vector<string> v = split(str, " ");
    print(v);
    return 0;
}