#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class Solution {
public: //注意只能往右往下移动
    int minPathSum(vector<vector<int>>& grid) {
        int dp[201][201];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i < grid.size();i ++){
            for(int j = 0;j < grid[0].size(); j++){
                if(i == 0 && j == 0) dp[i][j] = grid[0][0];
                if(j == 0 && i) dp[i][j] = dp[i - 1][j] + grid[i][j];
                if(i == 0 && j) dp[i][j] = dp[i][j - 1] + grid[i][j]; 
                if(i && j) dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};
int main(){
    Solution s;
    //cout<<s.minPathSum()

    system("pause:");
    return 0;
}