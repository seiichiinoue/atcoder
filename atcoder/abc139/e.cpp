#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; ++i)
#define MAX 1e3+50
using namespace std;
typedef pair<int, int> P;


int main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n-1));
    rep(i,n) {
        rep(j, n-1) {
            cin >> a[i][j];
            a[i][j]--;
        }
        reverse(a[i].begin(), a[i].end());
    }
    vector<P> q;
    auto check = [&](int i) {   // lambda
        if (a[i].size() == 0) return;
        int j = a[i].back();
        if (a[j].size() == 0) return;
        if (a[j].back() == i) {
            if (i > j) swap(i, j);
            q.push_back(P(i,j));
        }
    };
    rep(i,n) {
        check(i);
    }
    int day = 0;
    while (q.size() > 0) {
        day++;
        sort(q.begin(), q.end());
        q.erase(unique(q.begin(), q.end()), q.end());
        vector<P> prevQ; swap(prevQ, q);
        for (P p : prevQ) {
            int i = p.first, j = p.second;
            a[i].pop_back();
            a[j].pop_back();
            // 試合を行なって変化するのは試合を行なった人たちだけ
            check(i);
            check(j);
        }
    }
    rep(i, n) {
        if (a[i].size() != 0) {
            puts("-1");
            return 0;
        }
    }
    cout << day << endl;
    return 0;
}
