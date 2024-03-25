#include <bits/stdc++.h>
using namespace std;

// 성적이 낮은 순서로 학생 출력하기 (정렬 Alg.)

// 시간 제한: 1초, 메모리 제한: 128MB
// N명의 학생 정보 (학생의 이름 학생의 성적)
// 성적이 낮은 순서대로 학생의 이름을 출력하는 프로그램
// (1 <= N <= 100,000) 

int n;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
struct student
{
    string name;
    int score;
};
bool compare(const student &a, const student &b)
{
    return a.score <= b.score;
}
int main()
{
    fastIO();
    student st[100001];
    cin >> n;
    if(n<1 || n>100000) exit(0);
    for(int i=0; i<n; i++)
    {
        cin >> st[i].name >> st[i].score;
    }
    sort(st, st+n, compare);
    for(int i=0; i<n; i++)
    {
        cout << st[i].name << " ";
    }
    cout << "\n";
    return 0;
}