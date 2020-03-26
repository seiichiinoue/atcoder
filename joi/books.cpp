#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define drep(i, n) for (int i=n; i>=0; --i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<vector<int>> b(10), v(10);
    vector<ll> dp(2000);
    rep(i, n) {
        int c, g; cin >> c >> g; g--;
        b[g].push_back(c);
    }
    rep(i, 10) {
        sort(RALL(b[i]));
        v[i].push_back(0);
    }
    rep(i, 10) rep(j, b[i].size()) v[i].push_back(v[i][j]+b[i][j]+j*2);
    rep(i, 10) drep(j, k) {
        for (int h=max(0, j-(int)v[i].size()+1); h<j; ++h) {
            chmax(dp[j], dp[h]+v[i][j-h]);
        }
    }
    cout << dp[k] << endl;
    return 0;
}