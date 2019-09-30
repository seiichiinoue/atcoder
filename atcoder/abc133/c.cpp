#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(){
    ll l, r; cin >> l >> r;
    ll ans = 1LL<<59;
    for(ll i=l; i<=min(r,l+2019); ++i){
        for(ll j=i+1; j<=min(r, i+2020); ++j){
            chmin(ans, (i*j)%2019);
        }
    }
    cout << ans << endl;
}