#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int,vector<int>> pq;
        int n = nums.size(),score = 0;
        for (int i = 0; i < n; i ++) {
            pq.emplace(nums[i]);
        }
        while (pq.size()&&k)
        {
            int t = pq.top();
            pq.pop();
            score += t;
            pq.push(t/3 + (t%3)?1:0);
            k --;
        }
        return score;
    }
};