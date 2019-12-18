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
typedef pair<ll, ll> P;
constexpr ll  MOD = (1e9+7);
constexpr int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
constexpr int lcm(int a, int b) { return a / gcd(a, b) * b; }

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
ll factorial(ll n, ll m=2) {
    // calculate n!
    m = max(2LL, m);
    ll rtn = 1;
    for (ll i=m; i<=n; i++) {
        rtn = (rtn * i) % MOD;
    }
    return rtn;
}
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

// 1 : chokudai -1 : naoko
// vector<vecrtor<int>> field(3, vector<int>(3, 0));
vector<vector<int>> b(2, vector<int>(3));
vector<vector<int>> c(3, vector<int>(2));
map<vector<vector<int>>, int> memo;

// chokudai's point - naoko's point
int calc_score(vector<vector<int>> &field) {
    int chokudai = 0, naoko = 0;
    rep(i, 2) rep(j, 3) {
        if (field[i][j] == field[i+1][j]) chokudai += b[i][j];
        else naoko += b[i][j];
    }
    rep(i, 3) rep(j, 2) {
        if (field[i][j] == field[i][j+1]) chokudai += c[i][j];
        else naoko += c[i][j];
    }
    return chokudai - naoko;
}

int search(int turn, vector<vector<int>> field) {
    if (turn == 10) return memo[field] = calc_score(field);
    if (memo.count(field)) return memo[field];
    int ret = (turn%2) ? -INF : INF;
    rep(i, 3) rep(j, 3) {
        if (field[i][j] == -1) {
            auto now = field;
            if (turn % 2) {
                now[i][j] = 1;
                ret = max(ret, search(turn+1, now));
            } else {
                now[i][j] = 0;
                ret = min(ret, search(turn+1, now));
            }
        }
    }
    return memo[field] = ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int sum = 0;
    rep(i, 2) rep(j, 3) cin >> b[i][j], sum += b[i][j];
    rep(i, 3) rep(j, 2) cin >> c[i][j], sum += c[i][j];
    vector<vector<int>> field(3, vector<int>(3, -1));
    int diff = search(1, field);
    cout << (sum + diff) / 2 << endl;
    cout << (sum - diff) / 2 << endl;
    return 0;
}