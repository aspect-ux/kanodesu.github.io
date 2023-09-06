#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> power,ans(m,1);
        while(n > 0){
            power.insert(power.begin(),n%2);
            n /= 2;
        }
        vector<int> dp(power.size(),1);
        dp[0] = power[0];
        for (int i = 1; i < power.size(); i ++) {
            dp[i] = dp[i - 1] * power[i] % MOD;
        }
        for (int i = 0; i < m; i ++) {
            if (queries[i][0] == 0) ans[i] *= dp[queries[i][1]];
            else ans[i] *= dp[queries[i][1]] / dp[queries[i][0] - 1] % MOD;
        }
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}