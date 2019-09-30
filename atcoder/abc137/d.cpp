#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

priority_queue<int> Q;
vector<P> v;

int main() {
    ll n, m; cin >> n >> m;
    ll ans; 
    for (int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    
    int j = 0;
    for (int i=1; i<=m; ++i) {
        while (v[j].first<=i && j<v.size()) {
            Q.push(v[j].second);
            j++;
        }
        if (Q.size()==0) continue;
        int k = Q.top(); Q.pop();
        ans += k;
    }
    cout << ans << "\n";
}