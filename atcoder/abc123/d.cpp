#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
using namespace std;
typedef long long ll;

int main() {
    int x, y, z, K; cin >> x >> y >> z >> K;
    vector<ll> a(x), b(y), c(z), vec;
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    sort(RALL(a)); sort(RALL(b)); sort(RALL(c));
    rep(i, x) {
        rep(j, y) {
            rep(k, z) {
                if ((i+1) * (j+1) * (k+1) <= K) {
                    vec.push_back(a[i]+b[j]+c[k]);
                }
                else break;
            }
        }
    }
    sort(RALL(vec));
    rep(i, K) {
        cout << vec[i] << endl;
    }
    return 0;
}