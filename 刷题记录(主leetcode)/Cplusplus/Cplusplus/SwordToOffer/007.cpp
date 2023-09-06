#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //关键点在于 只要确定了前两个数 就只要看剩下一个数存不存在就行
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int first = 0; first < n; first ++) {
            if (first > 0 && nums[first] == nums[first - 1]){
                continue;
            }
            int third = n - 1;
            int target = -nums[first];
            for (int second = first + 1; second < n; second ++) {
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;
                while (second < third && nums[third] + nums[second] > target)
                    third --;
                if (second == third) break;
                if (nums[third] + nums[second] == target)
                    ans.push_back({nums[first],nums[second],nums[third]});
            }
        }
        return ans;
    }
};