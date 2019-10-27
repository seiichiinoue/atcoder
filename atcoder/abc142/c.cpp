#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    vector<ll> ans(n);
    rep(i, n) {
        ll a; cin >> a;
        ans[a-1] = i+1;
    }
    rep(i, n) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}