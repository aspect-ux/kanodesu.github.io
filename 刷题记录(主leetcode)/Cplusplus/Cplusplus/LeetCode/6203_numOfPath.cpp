#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i ++) dp[0][i] = grid[0][i] + grid[0][i - 1];
        for (int i = 1; i < m; i ++) dp[i][0] = grid[i][0] + grid[i - 1][0];
        for (int i = 1; i < m; i ++)
        {
            for (int j = 1; j < n; j ++)
            {
                dp[i][j] = dp[i - 1] 
            }
        }
    }
};
int main(){
    
    system("pause:");
    return 0;
}