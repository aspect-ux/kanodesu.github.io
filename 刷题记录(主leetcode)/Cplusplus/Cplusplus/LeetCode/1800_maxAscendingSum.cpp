#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(),ans = nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i ++)
        {
            if(nums[i] > nums[i - 1]) dp[i] = dp[i-1] + nums[i];
            else dp[i] = nums[i];
            ans = max(dp[i],ans);
        }
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}