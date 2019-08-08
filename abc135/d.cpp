#include <bits/stdc++.h>
using namespace std;

static const long long mod = 1000000007LL;
int n;
char str[100005];
int long long dp[100005][13];

int main() {
    cin >> str;
    n = strlen(str);
    int i, j, ki; 
    int long long res = 0;
    // dp[i][j] = 先頭i文字として考えられるもののうち，
    // 13で割ったあまりがjであるものの個数
    
    dp[0][0] = 1;
    for (i=0;i<n;++i) {
        int c;
        if (str[i]=='?') c = -1;
        else c = str[i] - '0';

        for (j=0;j<10;++j) {    // cの数字が決まっている時はその数字，決まっていない時は全通り
            if (c != -1 && c != j) continue;
            for (ki=0;ki<13;++ki) {
                dp[i+1][(ki*10+j)%13] += dp[i][ki];
            }
        }
        for (j=0;j<13;++j) {
            dp[i+1][j] %= mod;
        }
    }
    res = dp[n][5];
    cout << res << endl;
    return 0;
}