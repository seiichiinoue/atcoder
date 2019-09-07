#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; ++i) 
typedef long long ll;
typedef pair<ll, ll> P;

int main() {
    ll n, m; cin >> n >> m;
    vector<ll> A(n); rep(i, n) cin >> A[i];
    sort(A.begin(), A.end());
    vector<P> CB(m); 
    rep(i, m) {
        ll b, c; cin >> b >> c;
        CB[i] = P(c, b);
    }
    sort(CB.begin(), CB.end());
    reverse(CB.begin(), CB.end());
    int changed = 0;
    rep(i, m) {
        while (CB[i].first>A[changed] && CB[i].second>0 && changed<n) {
            A[changed] = CB[i].first;
            changed++;
            CB[i].second--;
        }
        if (CB[i].second>0) {
            break;
        }
    }
    ll ans = 0;
    rep(i, n) ans += A[i];
    cout << ans << endl;
    return 0;
}