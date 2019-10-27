#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

const double PI=3.14159265358979323846;

int main(){
 double a, b, x;
 cin >> a >> b >> x;
 double rest = a*a*b - x;
 double ans;
 double h = 2*rest/(a*a);
 if(h <= b){
        double sha = sqrt(a*a + h*h);
        ans = asin(h/sha);
        printf("%.6f\n", 180*ans/PI);
 } else {
     h = 2*x/(b*a);
     double sha = sqrt(b*b + h*h);
     ans = asin(h/sha);
     printf("%.6f\n", 90 - 180*ans/PI);
 }

}