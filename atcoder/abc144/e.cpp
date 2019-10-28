#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    vector<ll> f(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.rbegin(), f.rend());
    // binary search
    ll l = 0, r = 1e12;
    while (l < r) {
        ll mid = l + (r-l)/2;   // total cost
        ll need = 0;
        rep(i, n) need += max(0ll, a[i]-mid/f[i]);
        if (need <= k) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}