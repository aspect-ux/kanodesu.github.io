#include<iostream>
#include<cstring>
using namespace std;
class Solution {
public:
    int countDigitOne(int n) {
        if(n == 824883294) int dp[n];

        int dp[n+1],b = 0,sum = 0;
        memset(dp,0,sizeof(dp));
        if(n == 0) return 0;
        dp[1] = 1;
        sum = dp[1];
        for(int i = 2;i <=n ;i ++){
            int temp = i;
            while(temp > 0){
                b = temp % 10;
                if(b == 1) dp[i]++;
                temp /= 10;
            }
            sum += dp[i];
        }
        return sum;
    }
};
int main(){
    Solution s;
    cout<<s.countDigitOne(824883294);

    system("pause:");
    return 0;
}