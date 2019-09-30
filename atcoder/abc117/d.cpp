#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
    const ll bit = 41;
    ll n, k; cin >> n >> k;
    vector<ll> A(n); rep(i, n) cin >> A[i];
    vector<ll> cnt(bit, 0);
    rep(i, n) {
        ll a = A[i];    // i桁目(2^iの位)
        rep(j, bit) {
            if (a%2==1) cnt[j]++;   // ビットが立ってるやつを数える
            else cnt[j]--;          // 立ってない総数
            a /= 2;
        }
    }
    ll X = 0;
    rep(i, bit) {
        if (cnt[bit-i-1] < 0) {
            if (X+pow(2, bit-i-1) <= k) X += pow(2, bit-i-1);
        }
    }
    ll res = 0;
    rep(i, n) {
        res += X ^ A[i];
    }
    cout << res << endl;
    return 0;
}