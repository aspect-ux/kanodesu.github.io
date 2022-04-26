#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
//限定为动态规划，试一下深搜加回溯suanle
//只能向右向下移动  真就找规律
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n; j++){
                if(i == 0) dp[i][j] = 1;
                if(j == 0) dp[i][j] = 1;
                if(i != 0&& j != 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
int main(){
    Solution s;
    cout<<s.uniquePaths(1,2);


    system("pause:");
    return 0;
}