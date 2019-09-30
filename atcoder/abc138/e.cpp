#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; ++i)
typedef long long ll;
typedef pair<double, int> P;

vector<int> v[30]; // a to zが文字列の何番目にあるか

int main() {
    string s, t;
    cin >> s >> t;
    rep(i, s.length()) {
        v[s[i] - 'a'].push_back(i+1);
        v[s[i] - 'a'].push_back(i+1 + s.length());
    }
    rep(i, 30) {
        sort(v[i].begin(), v[i].end());
    }
    ll ans = 0;
    int id = 0;
    rep(j, t.length()) {
        if (v[t[j] - 'a'].empty()) {
            puts("-1");
            return 0;
        }
        // binary search
        int next = *upper_bound(v[t[j] - 'a'].begin(), v[t[j] - 'a'].end(), id);
        ans += next - id;
        id = next % s.length();
    }
    cout << ans << endl;
}