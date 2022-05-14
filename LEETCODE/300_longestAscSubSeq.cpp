#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1,dp[nums.size()],last = 1,first = 0;
        dp[0] = 1;
        for(int i = 1;i < nums.size(); i++){
            if(nums[first] > nums[last]){
                dp[i] = dp[i - 1] + 1;
                last = i;
            }
            else {
                dp[i] = dp[i - 1];
                first = i;
            }
        }
        return dp[nums.size() - 1];
    }
};
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int result = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > result) result = dp[i]; // 取长的子序列
        }
        return result;
    }
};
*/
int main(){

    system("pause:");
    return 0;
}