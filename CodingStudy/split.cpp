#include <bits/stdc++.h>
using namespace std;

// split함수 구현
vector<string> split(string input, string delimeter)
{
    long long pos = 0;
    vector<string> v;
    string token = "";
    while((pos = input.find(delimeter)) != string::npos)
    {
        token = input.substr(0, pos);
        input.erase(0, pos + delimeter.length());
        v.push_back(token);
    }
    v.push_back(input);
    return v;
}
int main()
{

    string str = "성민이는 다솜이와 최근에 많이 친해졌어요!", delimeter = " ";
    vector<string> v = split(str, delimeter);
    for(string s : v)
    {
        cout << s << "\n";
    }
    return 0;
}