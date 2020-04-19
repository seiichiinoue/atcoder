#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;

int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 1ll;
    for (ll i = k; i <= n; i++) {
        ll lb = i * (i - 1) / 2;
        ll rb = i * n - lb;
        if (lb > rb) break;
        ans += rb - lb + 1ll;
        ans %= mod;
    }
    cout << ans << endl;
}