#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<n; ++i)

const long long N = 2e5+5;
vector<long long> v[N];
long long val[N];

void dfs(long long w, long long p) {
    for (long long i : v[w]) {
        if (i == p) continue;
        val[i] += val[w];
        dfs(i, w);
    }
}

int main() {
    long long n, q; cin >> n >> q;
    rep(i,n-1) {
        long long x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    while (q--) {
        long long x, y;
        cin >> x >> y;
        val[x] += y;
    }
    dfs(1,0);
    for (int i=1; i<=n; ++i) cout << val[i] << " ";
    cout << endl;
    return 0;
}