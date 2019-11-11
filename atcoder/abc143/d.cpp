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
    int n; cin >> n;
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    // ここで昇順になるため，任意のa=l[i]より右にあるものb, cは b+c>aを満たす
    sort(ALL(l));   // nlogn
    int ans = 0;
    // rep(i, n) {
    //     int a = l[i];
    //     for (int j=i+1; j<n; ++j) {
    //         int b = l[j];
    //         for (int k=j+1; k<n; ++k) {
    //             int c = l[k];
    //             if (a+c<=b) {
    //                 break;
    //             } else if (a+b<=c) {
    //                 break;
    //             } else {
    //                 ++ans;
    //             }
    //         }
    //     }
    // }
    rep(b, n) {
        rep(a, b) {
            int ab = l[a]+l[b];
            int r = lower_bound(ALL(l), ab) - l.begin();
            // c = [l, r)    a < b < c
            int l = b+1;    // bよりも長い   
            ans += r-l;
        }
    }
    cout << ans << endl;
    return 0;
}