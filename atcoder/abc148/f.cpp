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

// template<class T> inline bool chmin(T& a, T b) {
//     if (a > b) {
//         a = b;
//         return true;
//     }
//     return false;
// }
// template<class T> inline bool chmax(T& a, T b) {
//     if (a < b) {
//         a = b;
//         return true;
//     }
//     return false;
// }
// ll factorial(ll n, ll m=2) {
//     // calculate n!
//     m = max(2LL, m);
//     ll rtn = 1;
//     for (ll i=m; i<=n; i++) {
//         rtn = (rtn * i) % MOD;
//     }
//     return rtn;
// }
// ll modinv(ll a, ll m) {
//     ll b = m, u = 1, v = 0;
//     while (b) {
//         ll t = a / b;
//         a -= t * b;
//         swap(a, b);
//         u -= t * v;
//         swap(u, v);
//     }
//     u %= m;
//     if (u < 0) u += m;
//     return u;
// }
// ll modpow(ll a, ll n) {
//     ll res = 1;
//     while (n > 0) {
//         if (n & 1)
//             res = res * a % MOD;
//         a = a * a % MOD;
//         n >>= 1;
//     }
//     return res;
// }

// int main() {
//     cin.tie(nullptr);
//     ios::sync_with_stdio(false);
//     int n, u, v; cin >> n >> u >> v;
//     u--; v--;
//     // vector<vector<int>> to(n-1);
//     vector<vector<int>> dp(n, vector<int>(n, INF));
//     rep(i, n-1) {
//         int a, b; cin >> a >> b;
//         a--; b--;
//         // to[a].push_back(b);
//         // to[b].push_back(a);
//         dp[a][b] = 1;
//         dp[b][a] = 1;
//     }
//     rep(k,n) {
//         rep(i,n) {
//             rep(j,n){
//                 dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
//             }
//         }
//     }
//     cout << dp[u][v]/2 << endl;
//     rep(i, n) {
//         rep(j, n) {
//             if (i != j && dp[i][j] != INF)
//             cout << "cost from " << i << " to " << j << ": " << dp[i][j] << endl;
//         }
//     }
//     return 0;
// }

// struct WeightedGraph {

// };

// template< typename T >
// pair< T, int > dfs(const WeightedGraph< T > &g, int idx, int par) {
//   pair< T, int > ret(0, idx);
//   for(auto &e : g[idx]) {
//     if(e.to == par) continue;
//     auto cost = dfs(g, e.to, idx);
//     cost.first += e.cost;
//     ret = max(ret, cost);
//   }
//   return ret;
// }

// template< typename T >
// T tree_diameter(const WeightedGraph< T > &g) {
//   auto p = dfs(g, 0, -1);
//   auto q = dfs(g, p.second, -1);
//   return (q.first);
// }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, u, v; cin >> n >> u >> v;
    u--; v--;
    // vector<vector<int>> to(n-1);
    vector<vector<int>> dp(n, vector<int>(n, INF));
    map<int, int> mp;
    rep(i, n-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        // to[a].push_back(b);
        // to[b].push_back(a);
        dp[a][b] = 1;
        dp[b][a] = 1;
        mp[a]++;
        mp[b]++;
    }
    rep(k,n) {
        rep(i,n) {
            rep(j,n){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    cout << dp[u][v]/2 << endl;
    rep(i, n) {
        rep(j, n) {
            if (i != j && dp[i][j] != INF)
            cout << "cost from " << i << " to " << j << ": " << dp[i][j] << endl;
        }
    }
    return 0;
}