#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

// int main() {
//     priority_queue<ll, vector<ll>, greater<ll>> q;
//     ll q_zero = 0;
//     vector<ll> f;
//     ll n, k; cin >> n >> k;
//     rep(i, n) {
//         ll a; cin >> a;
//         q.push(a);
//     }
//     rep(i, n) {
//         ll tmp; cin >> tmp;
//         f.push_back(tmp);
//     }
//     sort(f.rbegin(), f.rend());
//     rep(i, k) {
//         ll tmp = q.top();
//         if (tmp==0) {
//             ++q_zero;
//             q.pop();
//             tmp = q.top();
//             q.pop();
//             --tmp;
//             q.push(tmp);
//         } else {
//             q.pop();
//             --tmp;
//             q.push(tmp);
//         }
//     }
//     ll ans = 0;
//     rep(i, n) {
//         if (q_zero>0) {
//             --q_zero;
//             continue;
//         } else {
//             ll tmp = q.top();
//             q.pop();
//             ans = max(ans, f[i] * tmp);
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }