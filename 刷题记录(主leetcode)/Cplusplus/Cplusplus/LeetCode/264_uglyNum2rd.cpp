#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        int q2 = 0, q3 = 0, q5 = 0;
        vector<int> dp(n, 0);

        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            dp[i] = min(dp[q2] * 2, min(dp[q3] * 3, dp[q5] * 5));

            if (dp[i] == dp[q2] * 2) q2++;
            if (dp[i] == dp[q3] * 3) q3++;
            if (dp[i] == dp[q5] * 5) q5++;
        } 

        return dp[n - 1];
    }
};
int main(){
   
    system("pause:");
    return 0;
}