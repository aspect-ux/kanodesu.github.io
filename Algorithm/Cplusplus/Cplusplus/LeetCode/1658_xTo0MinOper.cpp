#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(),ans = INT32_MIN;;
        long sum = 0,sum1 = 0;
        for (int i= 0; i < n; i ++) {
            sum += nums[i];
        }
        if (sum == x) ans = n;
        for (int i = 0,j = 0; j < n; j ++) {
            sum1 += nums[j];
            while (i < j && sum - sum1 < x)
            {
                sum1 -= nums[i];
                i ++;
            }
             if (sum - sum1 == x) ans = max(ans,j - i + 1);
        }
        return ans;
    }
};