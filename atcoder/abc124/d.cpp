#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
using namespace std;
typedef long long ll;

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> nums;
    int now = 1; // 今見ている数
    int cnt = 0; // いくつ並んでいるか
    rep(i, n) {
        if (s[i] == (char)('0' + now)) cnt ++;
        else {
            nums.push_back(cnt);
            now = 1 - now;
            cnt = 1;
        }
    }
    if (cnt != 0) nums.push_back(cnt);
    if (nums.size()%2==0) nums.push_back(0);

    int add = 2 * k + 1;
    int ans = 0;
    int left = 0;
    int right = 0;
    int tmp = 0;
    for (int i=0; i<nums.size(); i+=2) {
        // int tmp = 0;
        int nl = i;
        int nr = min(i+add, (int)nums.size());
        while (nl > left) {
            tmp -= nums[left];
            left++;
        }
        while (nr > right) {
            tmp += nums[right];
            right++;
        }
        ans = max(tmp, ans);
    }
    cout << ans << endl;
    return 0;
}