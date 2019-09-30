#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int long long> a(N);
    for (int i=0; i<N; ++i) cin >> a[i];
    int ans = 0;
    for (int i=0; i<N; ++i) ans += a[i] - 1;
    cout << ans << endl;
}   