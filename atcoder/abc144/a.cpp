#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
    int a, b; cin >> a >> b;
    if (a<10 && b<10) {
        cout << a*b << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}