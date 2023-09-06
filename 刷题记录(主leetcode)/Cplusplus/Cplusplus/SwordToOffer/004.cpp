#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hash;
        for (int i = 0; i < nums.size(); i ++) {
            hash[nums[i]] ++;
        }
        for (auto c : hash) 
            if (c.second == 1) return c.first;
        return 0;

    }
};
//不能使用额外空间
class Solution_1 {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(),cnt = 1;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < n;i ++) {
            if (nums[i] == nums[i + 1]) cnt ++;
            else {
                if (cnt == 3) {
                    cnt = 1;
                    continue;
                }
                else return nums[i];
            }
        }
        return 0;
    }
};
