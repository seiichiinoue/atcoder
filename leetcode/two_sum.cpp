#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i=0; i<nums.size(); ++i) {
            int ret = m[target - nums[i]];
            vector<int> ans = {ret-1, i}; 
            if (ret) return ans;
            m[nums[i]] = i+1;
        }
        return {0, 0};
    }
};