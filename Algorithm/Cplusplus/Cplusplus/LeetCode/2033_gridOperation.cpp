#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compute(vector<int> nums,int target,int x)
    {
        int n = nums.size(),cnt = 0;
        for (int i = 0; i < n; i ++) {
            int m = abs(nums[i] - target)%x;
            if (m == 0) cnt += abs(nums[i] - target)/x;
            else return -1;
        }
        return cnt;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(),n = grid[0].size();
        vector<int> nums;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++)
            {
                nums.push_back(grid[i][j]);
            }
        }
        int t = nums.size(),target = 0;
        if (t % 2) {
            int s = compute(nums,nums[t/2],x);
            if (s == -1) return -1;
            else return s;
        }else {
            int a = compute(nums,nums[t/2],x),b = compute(nums,nums[t/2-1],x);
            if (-1 != b && a != -1)  return min(a,b);
            else max(a,b);
        }
    }
};