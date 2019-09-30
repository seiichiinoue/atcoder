#include <bits/stdc++.h>
using namespace std;


int main() {
    int array[10] = {1, 3, 7, 6, 4, 0, 5, 2, 9, 8};
    cout << &array[9] << endl;  // 0x7ffee71b8954
    cout << array+9 << endl;    // 0x7ffee71b8954
}