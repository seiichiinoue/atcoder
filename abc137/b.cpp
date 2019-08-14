#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, x; cin >> k >> x;
    int start = x-k+1, end = x+k;
    for (int i=start; i<end; ++i) cout << i << " ";
    cout << endl;
}