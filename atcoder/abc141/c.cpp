#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, q; cin >> n >> k >> q;
    vector<int> a(n, k-q);
    for (int i=0; i<q; ++i) {
        int tar; cin >> tar;
        ++a[tar-1];
    }
    for (int i=0; i<n; ++i) {
        string ans = (a[i]>0) ? "Yes" : "No";
        cout << ans << endl;
    }
}