#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
typedef long long ll;
constexpr ll  MOD = (1e9+7);

using namespace std;

typedef long long ll;

struct fenwick_tree {
    typedef ll T;
    T n;
    vector<T> bit;

    // 各要素の初期値は 0 
    fenwick_tree(T num) : bit(num+1, 0) { n = num; }

    // a_i += w
    void add(T i, T w) {
        for (T x = i; x <= n; x += x & -x) {
            bit[x] += w;
        }
    }
    // [1, i] の和を計算.
    T sum(T i) {
        T ret = 0;
        for (T x = i; x > 0; x -= x & -x) {
            ret += bit[x];
        }
        return ret;
    }
    // [left+1, right] の和を計算.
    T sum(T left, T right) {
        return sum(right) - sum(left);
    }
};

int main() {
    ll n, k; cin >> n >> k;

    vector<ll> a(n);
    vector<ll> b(n);

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.begin(), b.end());
    map<ll, ll> mp;

    for(ll i = 0; i < n; i++) {
        mp[b[i]] = i+1;
    }

    fenwick_tree ft(n+1);
    ll tmp1 = 0;

    for (ll j = 0; j < n; j++) {
        tmp1 += j - ft.sum(mp[a[j]]);
        tmp1 %= MOD;
        ft.add(mp[a[j]], 1);
    }

    vector<ll> a2(n*2);
    vector<ll> b2(n*2);
    for (ll i=0; i<n*2; ++i) {
        a2[i] = a[i%n];
        b2[i] = a2[i];
    }
    sort(b2.begin(), b2.end());
    map<ll, ll> mp2;
    for (ll i=0; i<n*2; ++i) {
        mp2[b2[i]] = i+1;
    }
    fenwick_tree ft2(n*2+1);
    ll tmp2 = 0;

    for (ll j = 0; j < n*2; j++) {
        tmp2 += j - ft2.sum(mp2[a2[j]]);
        tmp2 %= MOD;
        ft2.add(mp2[a2[j]], 1);
    }
    tmp2 -= 2*tmp1;

    cout << (tmp1*k+(k*(k-1)/2)%MOD*tmp2)%MOD << endl;
    return 0;
}