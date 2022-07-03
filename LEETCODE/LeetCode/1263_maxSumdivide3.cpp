#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
class Solution {
public:
    int maxSumDivThree(vector<int>& nums){
        int dp[nums.size()][nums.size()];
        memset(dp,0,sizeof(dp));
        int front = 0;
        front = nums[0]%3==0?nums[0]:0;
        for(int i = 1;i < nums.size(); i++){
            //现在的最优解不一定是以后的最优解，dp的意义在于保存以后可能最优的解
            int temp = front%3==0?front:0;
            front += nums[i];
            temp = max(front%3==0?front:0,nums[i]%3==0?nums[i]:0);
            dp = max(dp,temp);
        }
        return dp;
    }
};
int main(){

    system("pause:");
    return 0;
}