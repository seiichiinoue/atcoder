#include <bits/stdc++.h>
#define max 100010
using namespace std;

int main() {
    char str[max]; cin >> str;
    int i; char tmp = 'R';
    int ans[max]={};
    int cnt=0, j=0, len=strlen(str);
    for (int i=0; i<len;i++) {
        if (tmp==str[i]) {
            cnt++;
            continue;
        }
        if (tmp=='R') {
            j=i; 
            ans[j] += cnt/2;
            ans[j-1] += (cnt+1)/2;
        } else {
            ans[j-1] += cnt/2;
            ans[j] += (cnt+1)/2;
        }
        cnt = 1;
        tmp=str[i];
    }
    ans[j-1] += cnt/2;
    ans[j] += (cnt+1)/2;
    int nn = strlen(str);
    for (int i=0; i<nn; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}