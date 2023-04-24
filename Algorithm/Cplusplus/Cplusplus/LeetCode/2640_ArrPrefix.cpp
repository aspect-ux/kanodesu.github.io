#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size(),t = 0;
        vector<long long> ans(n);
        for (int i = 0; i < n; i ++) {
            t = max(t,nums[i]);
            ans[i] = nums[i] + t;
        }
        for (int i = 1; i < n; i ++)
        {
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};