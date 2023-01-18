#include <bits/stdc++.h>
using namespace std;
class MKAverage {
public:
    int m,k;
    vector<int> nums;
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }
    void addElement(int num) {
        if (nums.size() == m)
            nums.erase(nums.begin());
        nums.push_back(num);
    }
    int calculateMKAverage() {
        if (nums.size() < m) return -1;
        long long ans = 0;
        int start = k,n = m - 2*k;
        sort(nums.begin() + k,nums.begin() + n + start);
        vector<int> t;
        for (int i = start; i < start + n; i ++)
        {
            ans += nums[i];
            t.push_back(nums[i]);
        }
        nums = t;
        return ans/n;
    }
};