#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int ans = 0;
    void dfs(vector<int>& nums, int target,int pos,int sum){
        if(pos == nums.size()){
            if(sum == target) ans++;
            return;
        }
        dfs(nums,target,pos + 1,sum + nums[pos]);
        dfs(nums,target,pos + 1,sum - nums[pos]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(nums,target,0,0);
        return ans;
    }
};
int main(){

    system("pause:");
    return 0;
}