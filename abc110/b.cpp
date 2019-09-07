#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; ++i)
typedef long long ll;

int main() {
    int n, m, x, y; cin >> n >> m >> x >> y;
    int X[n], Y[m];
    rep(i, n) cin >> X[i];
    rep(i, m) cin >> Y[i];
    sort(X, X+n);
    sort(Y, Y+m);
    if (Y[0] - X[n-1] > 0) {
        for (int i=X[n-1]+1; i<=Y[0]; ++i) {
            if (i>x && i<=y) {
                puts("No War");
                return 0;
            }
        }
    }
    puts("War");
    return 0;
}