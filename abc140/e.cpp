#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; ++i)
typedef long long ll;

int main() {
    int n; cin >> n;            // 8
    vector<int> a(n); 
    rep(i, n) cin >> a[i];
    rep(i, n) a[i]--;           // 7 1 6 2 3 4 5 0
    vector<int> idx(n);
    rep(i, n) idx[a[i]] = i;    // 7 1 3 4 5 6 2 0  (a[i]のidx)
    set<int> s;                 // ascending order
    ll ans = 0;
    // 大きい順でみていく
    for (int x=n-1; x >=0; --x) {
        int i = idx[x];
        ll c = 0;
        {   // calc c
            s.insert(i);
            vector<int> l(2, -1), r(2, n);  // x, w, y, z
            {   // calc l
                auto it = s.find(i);
                rep(j, 2) {
                    if (it == s.begin()) break;
                    --it;
                    l[j] = *it;
                }
            }
            {   // calc r
                auto it = s.find(i);
                rep(j, 2) {
                    ++it;
                    if (it == s.end()) break;
                    r[j] = *it;
                }
            }
            vector<int> ls(2);
            ls[0] = i-l[0]; ls[1] = l[0]-l[1];
            vector<int> rs(2);
            rs[0] = r[0]-i; rs[1] = r[1]-r[0];
            c = (ll)ls[0]*rs[1] + (ll)ls[1]*rs[0];
        }
        ans += c*(x+1);
    }
    cout << ans << endl;
    return 0;
}