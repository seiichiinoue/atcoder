#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; ++i)
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<ll> S(n); rep(i, n) cin >> S[i];
    sort(S.begin(), S.end());
    ll max_s = S[n-1];
    ll tar = max_s;
    ll cur_num = 0;
    ll day = 0;
    for (int i=max_s; i>0; --i) {
        ll tmp = 0;
        rep(j, n) {
            if (S.back() != tar) {
                tar = S.back();
                break;
            }
            else {
                tmp++;
                cur_num++;
                S.pop_back();
            }
        }
        ll tmp2;
        if (tmp % cur_num == 0) tmp2 = tmp / cur_num;
        else tmp2 = tmp / cur_num +1;
        day += tmp2;
        if (day > n) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}