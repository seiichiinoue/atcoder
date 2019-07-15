#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; ++i) cin >> A[i];
    vector<int> r(N);
    for (int i=0; i<N; ++i) r[0] += A[i] * (i%2==0 ? 1:-1);
    for (int i=1; i<N; ++i) r[i] = 2 * A[i-1] - r[i-1];
    for (int i=0; i<N; ++i){
        cout << r[i] << (i==N-1 ? '\n':' ');
    }
}