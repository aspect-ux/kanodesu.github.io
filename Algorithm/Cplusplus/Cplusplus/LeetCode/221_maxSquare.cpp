#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(),n = matrix[0].size(),ans = 0;
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = matrix[i][j] - 48;
                }
                else{
                    if((int)(matrix[i][j] - 48)){
                        if(dp[i - 1][j] == dp[i][j - 1] && dp[i - 1][j] && dp[i - dp[i-1][j]][j - dp[i - 1][j]]){
                            dp[i][j] = dp[i - 1][j] + 1;
                        }else if(dp[i-1][j]&&dp[i][j-1]){
                            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + 1;
                        }else{
                            dp[i][j] = 1;
                        }
                        ans = max(ans,dp[i][j]);
                    }
                    else dp[i][j] = 0;
                }
            }
           
        }
         return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}