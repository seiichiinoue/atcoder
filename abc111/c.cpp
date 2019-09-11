#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main() {
    int n; cin >> n;
    vector<P> v(n/2);
    rep(i, n/2) {
        int a, b;
        cin >> a >> b;
        v.push_back(P(a, b));
    }
    
    cout << ret << endl;
    return 0;
}