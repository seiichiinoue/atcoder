#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> p(n+1); for (int i=1; i<=n; ++i) cin >> p[i];
    int cnt = 0;
    for (int i=1; i<n+1; ++i) {
        if (p[i] != i) cnt += 1;
    }
    if (cnt<=2) {
        cout << "YES" << endl;
    } else {
        cout << "NO"<< endl;
    }
    return 0;
}