#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    rep1(i, 9) {
        rep1(j, 9) {
            if (i*j==n) {
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}