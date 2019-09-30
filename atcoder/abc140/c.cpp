#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; ++i)
typedef long long ll;

int main() {
    int n; cin >> n;
    ll B[n-1]; rep(i, n-1) cin >> B[i];
    ll ans = 0;
    ll prev = 1000000;
    rep(i, n) {
        if (i==n) {
            ans += B[n-1];
        } else {
            ans += min(prev, B[i]);
            prev = B[i];
        }
    }
    cout << ans << endl;
    return 0;
}