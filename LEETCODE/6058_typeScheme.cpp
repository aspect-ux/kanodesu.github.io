#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// 1   1
// 2   2
// 3   4
//？4   7

//1  2     3        4    4+2+1=7
class Solution {
public:
    static const long long mod = 1e9 + 7;
    int countTexts(string pressedKeys) {
        vector<long long> dp(pressedKeys.size(),1);
        int cnt = 1,ans = 0;
        for(int i = 1; i < pressedKeys.length(); i++){
            if(pressedKeys[i - 1] == pressedKeys[i]) cnt++;
            else cnt = 1;
            if(cnt == 1) dp[i] = dp[i - 1];
            if(cnt == 2&&i>=cnt) dp[i] = dp[i - 1] + dp[i - 2];
            else if(cnt == 2&&i<cnt) dp[i] = 2;
            if(pressedKeys[i] != '9'&& pressedKeys[i] != '7') {
                if(cnt == 3&&i<cnt) dp[i] = 4;
                if(cnt >= 3&&i>=cnt) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
            }
            else {
               if(cnt == 4&& i<cnt) dp[i] = 7;
                if(cnt >= 4&& i>=cnt) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
            }
            cout<<dp[i]<<' '<<cnt<<' '<<i - 1<<endl;
        }
        return (int)(dp[pressedKeys.size() - 1]%mod);
    }
};
int main(){
    Solution s;
    cout<<s.countTexts("9999333399993333788");
    system("pause:");
    return 0;
}