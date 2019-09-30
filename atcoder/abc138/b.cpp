#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    double a, ans; ans = 0.0;
    for (int i=0; i<n; ++i) {
        cin >> a;
        ans += 1.0 / a;
    }
    ans = 1.0 / ans;
    cout << setprecision(16) << ans << endl;
}