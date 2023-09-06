#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(const vector<int>& nums, int m, int p) {
        int n = nums.size();
        for (int i = 0; i < n-1 && p > 0; i++) {
            if (nums[i+1]-nums[i] <= m) {
                p--;
                i++;
            }
        }
        return p == 0;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        
        int l = 0, r = nums.back() - nums[0], m;
        while (l < r) {
            m = (l + r) >> 1;
            if (check(nums, m, p)) r = m;
            else l = m + 1;
        }
        return l;
    }
};

int main()
{
    return 0;
}