#include<iostream>
#include<vector>
#include<cstring>
using namespace std; //递归不好弄
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> dp(temperatures.size(),0);
        int flag = 0;
        for(int i=0; i< temperatures.size(); i++){
            for(int j = i + 1; j < temperatures.size(); j++){
                if(temperatures[j] > temperatures[i]){
                    dp[i] = j - i;
                }
            }
        }
        return dp;
    }
};
int main(){

    system("pause:");
    return 0;
}