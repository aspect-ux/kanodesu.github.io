#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[nums.size()],ans = 0;
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for(int i = 2;i < nums.size(); i++){
            int temp = 0;
            for(int j = i - 2; j >= 0; j -- ){
                temp = max(temp,dp[j] + nums[i]);
            }
            dp[i] = temp;
            ans = max(ans,dp[i]);
        }
        //不要忘了，前两个dp值还没有比较
        return max(ans,dp[1]);

    }
};
int main(){
    Solution s;
    vector<int> nums={6,6,4,8,4,3,3,10};
    cout<<s.rob(nums);

    system("pause:");
    return 0;
}