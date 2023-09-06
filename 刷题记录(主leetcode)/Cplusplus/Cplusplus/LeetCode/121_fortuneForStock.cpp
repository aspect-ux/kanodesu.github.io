#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),tmp = prices[0];
        if(n == 1)return 0;
        vector<int> dp(n,0);
        dp[0] = 0;
        for(int i = 1;i < n;i ++){
            dp[i] = max(dp[i-1],prices[i] - tmp);
            if(prices[i] < tmp) tmp = prices[i];
        }
        return dp[n - 1];
    }
};
int main(){
   
    system("pause:");
    return 0;
}