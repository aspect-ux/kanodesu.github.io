#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int dp[prices.size()];
        dp[0] = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            dp[i] = max(dp[i - 1],dp[i - 1] + dp[i]);
        }
        return dp[prices.size() - 1];

    }
};
int main(){

    system("pause:");
    return 0;
}