#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(),ans = 0;
        long sum = 0;
        for (int i = 0,j = 0; i < n; i ++) {
            sum += nums[i];
            while (sum > k) {
                sum -= nums[j];
                j ++;
            }
            if (sum == k) ans ++;
        }
        return ans; 
    }
};
class Solution_1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x:nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
}