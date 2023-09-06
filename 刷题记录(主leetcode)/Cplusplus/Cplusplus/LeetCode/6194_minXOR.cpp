#include<iostream>
#include<vector>
using namespace std;
//65 1 0 0 0 0 0 1
//84 1 0 1 0 1 0 0   3

//   1 000000000 1 1
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt2 = 0,cnt1 = 0,flag = 0,ans = 0;
        vector<int> dp;
        while(num2 > 0){
            if(num2%2) cnt2 ++;
            num2 /= 2;
        }
        while(num1 > 0){
            dp.push_back(num1%2);
            if(num1%2) cnt1 ++;
            num1 /= 2;
        }
        cout<<cnt2;
        for(int i = dp.size() - 1; i >= 0; i --){
            if(!flag) ans = ans * 2 + dp[i];
            if(dp[i]&&!flag){
                cnt2 --;
                if(cnt2 == 0) flag = 1;
            }
            else ans = ans * 2 + 0;
        }
        if(cnt)
        if(!flag){
            for(int i = 0; i < cnt2; i ++){
                ans = ans*2 + 1;
            }
        }
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}