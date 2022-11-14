#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 0,n = s.length(),cnt = 1;
        vector<int> dp(n,0);
        dp[0] = 1;
        for(int i = 1; i < n; i ++){
            if(s[i] - s[i-1] == 1){
                cnt ++;
            }else cnt = 1;
            ans = max(cnt,ans);
        }
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}
