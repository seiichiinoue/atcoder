#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
    ll n, m; cin >> n >> m;
    priority_queue<ll> q;   // greatest
    rep(i, n) {
        ll a; cin >> a;
        q.push(a);
    }
    rep(i, m) {
        ll top = q.top();
        q.pop();
        top /= 2;
        q.push(top);
    }
    ll ans = 0;
    rep(i, n) {
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}