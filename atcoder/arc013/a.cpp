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
    int n, m, l; cin >> n >> m >> l;
    int p, q, r; cin >> p >> q >> r;
    int ans = 0;
    ans = max(max((n/p)*(m/q)*(l/r),(n/p)*(m/r)*(l/q)),max((n/q)*(m/p)*(l/r),(n/r)*(m/p)*(l/q)));
    ans = max(ans,max((n/r)*(m/q)*(l/p),(n/q)*(m/r)*(l/p)));
    cout << ans << endl;
    return 0;
}