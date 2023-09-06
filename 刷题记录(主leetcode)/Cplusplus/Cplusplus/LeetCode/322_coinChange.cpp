#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
    return x>y?y:x;
}
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = 0;
        sort(coins.rbegin(),coins.rend());
        for(int i = 0; i < coins.size(); i++){
            while(amount >= coins[i]){
                amount -= coins[i];
                ans ++;
            }
        }
        return ans;
    }
};
int main(){

    system("pause:");
    return 0;
}