#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        if(nums[1]-nums[0]>=2)return false;
        if(nums[1]-nums[0]==1){
            if(n == 2||nums[2] - nums[1]!=1) return false;
        }
       if(nums[1] == nums[0]) dp[0] = 1;
        for(int i = 1;i < n; i++){
            if(nums[i] == nums[i - 1]){
                if(i == 1 || (i >=2 && dp[i-2])||((nums[i]==nums[i-1]&&nums[i-1] == nums[i-2]&&dp[i-3])))
                dp[i] = 1;
            }
            if(i >= 2 && nums[i] == nums[i-1]+1 && nums[i-1] == nums[i-2]+1){
                if(i == 2 || i >=4 && dp[i-3]) 
                dp[i] = 1;
            }
        }
        return dp[n-1];
    }
};
int main(){
   
    system("pause:");
    return 0;
}