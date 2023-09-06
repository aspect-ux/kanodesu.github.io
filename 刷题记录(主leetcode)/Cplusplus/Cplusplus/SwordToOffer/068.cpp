#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0,high = nums.size() - 1,mid = (high - low) / 2 + low;
        while (low <= high) {
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid - 1;
            else {
                low = mid + 1;
            }
            mid = (high - low) / 2 + low;
        }
        return mid;
    }
};