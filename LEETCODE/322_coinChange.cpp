#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
    return x>y?y:x;
}
class Solution {
public:
    void dfs(vector<int>&coins,int &ans,int &amount){
        if(amount == 0) return;
        if(amount < 0){
            ans = -1;
            return;
        }
        for(int i = 0;i < coins.size(); i++){
            int a = amount, an = ans;
            a += amount%coins[i];
            an += amount / coins[i];
            dfs(coins,an,a);
        }
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = 0;
        dfs(coins,ans,amount); 
        return ans;
    }
};
int main(){

    system("pause:");
    return 0;
}