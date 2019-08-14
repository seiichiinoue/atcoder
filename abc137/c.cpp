#include <bits/stdc++.h>
using namespace std;

int main() {
    int long long n; cin >> n;
    map<string, int long long> mp;
    for (int i=0; i<n; ++i) {
        string t; cin >> t;
        sort(t.begin(), t.end());
        mp[t]++;
    }
    int long long ans = 0;
    for (auto x : mp) ans += x.second*(x.second-1)/2;   //nC2
    cout << ans << endl;
    return 0;
}