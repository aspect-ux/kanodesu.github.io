#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int ans = 0;
    void dfs(vector<int>& nums,int pos,int cnt,int dp[]){
        if(cnt == -1 || dp[pos]) return;
        ans++;
        dp[pos] = 1;
        dfs(nums,nums[pos],cnt - 1,dp);
    }
    int arrayNesting(vector<int>& nums){
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
        int dp[nums.size()];
        memset(dp,0,sizeof(dp));
        ans = 0;
        dfs(nums,i,i,dp);
        res = max(res,ans);
        }
        return res;
    }
};
int main(){

    system("pause:");
    return 0;
}