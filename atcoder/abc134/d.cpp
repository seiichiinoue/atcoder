#include <bits/stdc++.h>
using namespace std;

int main() {
    int long long n; cin >> n;
    vector<int> a(n+1); for (int i=1; i<=n; ++i) cin >> a[i];
    vector<int> ans(n+1);
    for (int i=n; i>=1; --i) {   // 後ろから見ていく
        int sum = 0;
        for (int j=i; j<=n; j+=i) {
            sum += ans[j];
        }
        if (sum%2 != a[i]) ans[i]++;
    }
    int m = 0;
    for (int i=1; i<=n; ++i) {
        m += ans[i];
    }
    cout << m << endl;
    for (int i=1; i<=n; ++i) {
        if (ans[i] == 1) cout << i << " ";
    }
    return 0;
}