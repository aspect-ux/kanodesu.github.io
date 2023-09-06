#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),maxv = nums[n - 1];
        unordered_map<int,vector<int>> hash;
        for (int i = 0; i < n ; i ++) {
            double t = nums[i];
            int cnt = 0,last = -1;
            while(1) {
                double tmp = sqrt(t);
                if ((int)tmp - tmp !=0) break;
                t = tmp;
                cnt ++;
            }
            if (last == nums[i]) continue;
            last = nums[i];
            hash[t].push_back(nums[i]);
        }
        maxv = 1;
        int ans = 0;
        for (auto c : hash) if (c.second.size() > maxv){
            for (int i = 0; i < c.second.size() - 1; i ++) {
                if (nums[i] * nums[i] == nums[i + 1]) maxv ++;
                else maxv = 1;
            ans = max(ans,maxv);
            }
        }
        return ans>1?ans:-1; 
    }
};