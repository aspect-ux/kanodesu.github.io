#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int q2 = 0, q3 = 0, q5 = 0,tmp = INT_MAX;
        vector<int> dp(n, 0);
        vector<int> p(n,0);
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            for(int j = 0;j < primes.size(); j++){
                tmp = min(dp[p[j]] * primes[j],tmp);
                dp[i] = tmp;
            }
            for(int j = 0; j < n; j++){
                if(dp[i] == dp[p[j]]*primes[j]) {
                    p[j]++;
                    break;
                }
            }
        } 
        return dp[n - 1];
    }
};
int main(){
   
    system("pause:");
    return 0;
}
