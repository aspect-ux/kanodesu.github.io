#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        vector<vector<int>> dp(n + 1,vector<int>(2));

        dp[1][0] = -prices[0], dp[1][1] = 0;// 有股票和没股票
        for(int i = 2; i <= n; i++){
            //维持不动或者前天卖今天买
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i - 1]);
            //维持不动或者昨天买今天卖
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i - 1]); 
        }
        return dp[n][1];
    }
};
int main(){

    system("pause:");
    return 0;
}