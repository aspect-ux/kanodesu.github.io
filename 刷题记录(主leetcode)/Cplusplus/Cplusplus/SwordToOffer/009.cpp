#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //超时
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(),ans = 0;
        for (int i = 0; i < n; i ++) {
            long multi = 1;
            for (int j = i; j >=0 ; j --) {
                multi *= nums[j];
                if (multi < k) ans ++;
                else break;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), ret = 0;
        int prod = 1, i = 0;
        for (int j = 0; j < n; j++) {
            prod *= nums[j];
            while (i <= j && prod >= k) {
                prod /= nums[i];
                i++;
            }
            ret += j - i + 1;//窗口长度 = 以右端点结尾数
        }
        return ret;
    }
};