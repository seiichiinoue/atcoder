#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
    ll a, b; cin >> a >> b;
    if (a>0 && b>0) {
        puts("Positive");
    } else if ((a>=0 && b<=0) || (a<=0 && b>=0)){
        puts("Zero");
    } else {
        ll c = -1 * (a+b) - 1;
        if (c % 2 == 0) {
            puts("Positive");
        } else {
            puts("Negative");
        }
    }
    return 0;
}