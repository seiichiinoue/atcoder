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
    int n, k; cin >> n >> k;
    int ans = 0;
    rep(i, n) {
        int tmp; cin >> tmp;
        if (tmp>=k) ans += 1;
    }
    cout << ans << endl;
    return 0;
}