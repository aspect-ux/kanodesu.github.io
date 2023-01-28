#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int odd,even = odd = 0,n = nums.size(),ans = 0,even1,odd1 = even1 = 0;
        for (int i = 0; i < n; i ++) {
            if (i % 2 == 0) even += nums[i];
            else odd += nums[i];
        }
        for (int i = 0 ; i < n; i ++) {
            if (i % 2 == 0) {
                even -= nums[i];
                if (even + odd1== odd + even1) ans ++;
                even1 += nums[i];
            }else {
                odd -= nums[i];
                if (even + odd1== odd + even1) ans ++;
                odd1 += nums[i];
            }
        }
        return ans;
    }
};