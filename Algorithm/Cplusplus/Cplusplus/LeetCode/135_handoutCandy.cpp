#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(),sum = 0;
        vector<int> dp(n),np(n);
        dp[0] = 1;
        np[n-1] = 1;
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                dp[i] = dp[i-1]+1;
            }
            if(ratings[n - i] < ratings[i - i - 1]){
                np[n - i - 2] = np[n - i - 1] + 1;
            }
        }
        for(int i = 0; i < n; i++){
            sum += max(dp[i],np[i]);
        }
    }   
};
int main(){
   
    system("pause:");
    return 0;
}