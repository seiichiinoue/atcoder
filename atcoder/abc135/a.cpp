#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    if (a%2 != b%2) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << (a+b)/2 << endl;
    }
    return 0;
}