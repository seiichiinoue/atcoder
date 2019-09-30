#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; ++i)
typedef long long ll;
typedef pair<ll, ll> P;
vector<P> cost_due;

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main() {
    int n; cin >> n;
    rep(i, n) {
        ll a, b; cin >> a >> b;
        cost_due.push_back(P(a, b));
    }
    // 締め切りを昇順にソート
    sort(cost_due.begin(), cost_due.end(), compare_by_b);
    ll current = 0;
    rep(i, n) {
        P a = cost_due[i];        
        if (current + a.first <= a.second) {
            current += a.first;
        } else {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}