#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

vector<P> factorizer(ll n) {
    vector<P> facts;
    for (ll p=2; p*p<=n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        facts.push_back(P(p, num));
    }
    if (n != 1) facts.push_back(P(n, 1));
    return facts;
}

int main() {
    vector<P> fa, fb;
    ll a, b; cin >> a >> b;
    fa = factorizer(a);
    fb = factorizer(b);
    ll ans = 0;
    rep(i, fa.size()) {
        rep(j, fb.size()) {
            if (fa[i].first == fb[j].first) ++ans;
        }
    }
    cout << ans + 1<< endl;
    return 0;
}