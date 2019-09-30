#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; ++i)
typedef long long ll;

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int total = 0;
    rep(i, n-1) {
        if (s[i] == s[i+1]) total++;
    }
    cout << min(n-1, total+(2*k)) << endl;
    return 0;
}