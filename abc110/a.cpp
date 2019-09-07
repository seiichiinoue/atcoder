#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; ++i)
typedef long long ll;

int main() {
    int a[3];
  	cin >> a[0] >> a[1] >> a[2];
  	sort(a, a+3);
  	int ans = a[2] * 10 + a[1] + a[0];
    cout << ans << endl;
    return 0;
}