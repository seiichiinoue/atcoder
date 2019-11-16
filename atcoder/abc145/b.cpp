#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    if (n%2!=0) {
        puts("No");
        return 0;
    } else {
        string tmp1 = "";
        string tmp2 = "";
        rep(i, n) {
            if (i<=n/2-1) tmp1 += s[i];
            else tmp2 += s[i];
        }
        if (tmp1 == tmp2) {
            puts("Yes");
            return 0;
        }
        else puts("No");
    }
    return 0;
}