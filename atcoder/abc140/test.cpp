#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; ++i)
typedef long long ll;

int main() {
    set<int> s;
    s.insert(1); s.insert(3); s.insert(0);
    auto it = s.find(1);
    cout << *it << endl;
    it++;
    cout << *it << endl;
    it--; it--;
    cout << *it << endl;
    it++;
    cout << *it << endl;
}