#include <bits/stdc++.h>
using namespace std;

// 사다리

double x, y, c;
double low, high, ret;
double sol(double mid)
{
    double h1 = sqrt(x*x - mid*mid);
    double h2 = sqrt(y*y - mid*mid);
 
    return (h1 * h2)/(h1 + h2);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> x >> y >> c;
    
    double high = min(x, y);
    while(high - low > 0.000001)
    {
        double mid = (low + high) / 2.0;
        
        if(sol(mid) >= c){
            ret = mid;
            low = mid;
        }
        else
            high = mid;
    }
    cout << fixed << setprecision(3) << ret << "\n";
    return 0;
}