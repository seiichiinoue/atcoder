#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
    string s; cin >> s;
    for (int i=0; s[i]; ++i) {
        if ((i%2==0&&s[i]=='L') || (i%2==1 && s[i]=='R')) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}