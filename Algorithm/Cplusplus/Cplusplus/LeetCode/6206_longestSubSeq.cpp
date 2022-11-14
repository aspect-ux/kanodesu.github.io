#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size(),ans = 0,cnt = 0;
        vector<int> dp(n,1);
        for(int i = n - 2; i >= 0; i--){
            if(nums[i+1]>nums[i]&&nums[i+1]-nums[i]<=k){
                dp[i] = dp[i+1] + 1;
            }
        }
        return dp[0];
    }
};
int main(){
   
    system("pause:");
    return 0;
}