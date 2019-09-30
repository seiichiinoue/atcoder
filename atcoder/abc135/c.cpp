#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    vector<int long long> a(n+1); for (int i=0; i<n+1; ++i) cin >> a[i];
    vector<int long long> b(n); for (int i=0; i<n; ++i) cin >> b[i];
    int long long num=min(a[0],b[0]), prev_num, next_num;
    int long long ans = 0;
    for (int i=0; i<n; ++i) {
        if (i>0) num = min(a[i]-prev_num, b[i]);
        next_num = min(a[i+1], b[i]-num);
        prev_num = next_num;
        ans += num + next_num;
    }
    cout << ans << endl;
}