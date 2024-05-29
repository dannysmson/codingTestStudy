#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string str;
bool flag=false;    // 입력조건 확인 위해 숫자의 자릿수 확인하는 변수
vector<string> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// 입력 문자열 분할하는 함수
vector<string> split(string s, string tokenizer)
{
    vector<string> ret;
    ll pos = 0;
    string token="";
    while((pos = s.find(tokenizer)) != string::npos)
    {
        token = s.substr(0, pos);
        if(s.size() == 3) flag = true;
        ret.push_back(token);
        s.erase(0, pos+tokenizer.length());
    }
    if(s.size() == 3) flag = true;
    ret.push_back(s);
    return ret;
}
bool comp1(string a, string b)
{
    int len1 = a.length();
    int len2 = b.length();
    if(len1 == len2)
    {
        return a < b;
    }
    int greater = max(len1, len2);
    for(int i=0; i<greater; i++)
    {
        if(a[i] != b[i])
        {
            return a[i] < b[i];
        } else {
            if(i == len1-1)
            {
                for(int j=i+1; j<greater; j++) return b[j] < a[i];
            } else if(i == len2-1)
            {
                for(int j=i+1; j<greater; j++) return a[j] < b[i];
            }
        }
    }
    return true;
}
/*
bool comp2(string a, string b)
{
    int len1 = a.length();
    int len2 = b.length();
    if(len1 == len2)
    {
        return a > b;
    }
    int greater = max(len1, len2);
    for(int i=0; i<greater; i++)
    {
        if(a[i] != b[i])
        {
            return a[i] > b[i];
        } else {
            if(i == len1-1)
            {
                for(int j=i+1; j<greater; j++) return b[j] < a[i];
                break;
            } else if(i == len2-1)
            {
                for(int j=i+1; j<greater; j++) return a[j] < b[i];
                break;
            }
        }
    }
    return true;
}
*/
void solution(vector<string> v)
{
    string minStr="", maxStr="";
    sort(v.begin(), v.end(), comp1);
    for(int i=0; i<v.size(); i++)
    {
        string s = v[i];
        minStr += s;
    }
    // sort(v.begin(), v.end(), comp2);
    for(int i=v.size()-1; i>=0; i--)
    {
        string s = v[i];
        maxStr += s;
    }
    ll sum1 = 0, sum2 = 0;
    sum1 = stoull(minStr);
    sum2 = stoull(maxStr);
    cout << sum1 << "\n";
    cout << sum2 << "\n";
    cout << sum1 + sum2 << "\n";

    return;
}
int main()
{
    getline(cin, str);
    v = split(str, " ");
    if(flag)
    {
        if(v.size() > 6)
        {
            cout << -1 << "\n";
            return 0;
        }
    } else 
    {
        if(v.size() > 9)
        {
            cout << -1 << "\n";
            return 0;
        }
    }
    solution(v);   
    return 0;
}
// 10 2 21 24 9
// 10 21 2 24 9

// 9 24 2 21 10
// 9 24 21 2 10

// 10212249
// 92422110