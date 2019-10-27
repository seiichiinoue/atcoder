#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef int long long ll;

int main() {
    ll n; cin >> n;
    ll ans = 1000000000000;
    for (ll i=1; i*i<=n; ++i){
        ll tmp = n / i;
        ll tmp2 = tmp + i;
        if (n%i==0 && tmp2<ans) {
            ans = tmp2;
        } else {
            continue;
        }
    }
    cout << ans - 2 << endl;
    return 0;
}