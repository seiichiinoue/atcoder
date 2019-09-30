#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; ++i)
typedef long long ll;

int main() {
    int n; cin >> n;
    int a[n], b[n], c[n-1];
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    rep(i, n) cin >> b[i];
    rep(i, n-1) cin >> c[i];
    int ans = 0;
    rep(i, n) {
        int tmp = b[a[i]];
        if (i > 0 && a[i-1]+1 == a[i]) tmp += c[a[i-1]];
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}