#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N); for (int i=0; i<N; ++i) cin >> A[i];
    int first = *max_element(A.begin(), A.end());
    int flg = 0;
    for (int j=0; j<N; ++j){
        if (A[j] == first) flg += 1;
    }
    int second = 0;
    for (int i=0; i<N; i++){
        if (A[i] != first && A[i] > second) second = A[i];
    }
    for (int i=0; i<N; i++){
        if (A[i] == first && flg == 1){
            cout << second << endl;
        } else {
            cout << first << endl;
        }
    }
    return 0;
}