#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<double> v(n,0.0); for (int i=0; i<n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i=1; i<n; ++i) {
        v[i] = (v[i]+v[i-1])/2.0;
        sort(v.begin(), v.end());
    }
    cout << fixed << setprecision(12) << v.back() << "\n";
    return 0;
}