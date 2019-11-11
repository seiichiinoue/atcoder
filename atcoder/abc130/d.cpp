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
    ll n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll ans=0, sum=0;
    ll r=0;
    rep(i, n) {
        while (sum<k) {
            if (r==n) break;
            else {
                sum += a[r];
                r++;
            }
        }
        if (sum < k) break;
        ans += n-r+1;
        sum -= a[i];
    }
    cout << ans << endl;
    return 0;
}