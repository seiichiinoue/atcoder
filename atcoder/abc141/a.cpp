#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
    string s; cin >> s;
    if (s=="Sunny") cout << "Cloudy";
    else if (s=="Cloudy") cout << "Rainy";
    else cout << "Sunny";
    cout << endl;
    return 0;
}