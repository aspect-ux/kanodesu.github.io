#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool cmp(int a,int b){
        return a>b;
    }
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(),matchsticks.end(),cmp);
        long long sum = 0;
        int n = matchsticks.size();
        vector<int> dp(n,0);
        for(int c : matchsticks) sum+=c;
        if(sum%4)return false;
        int avg = sum/4;
        if(matchsticks[0] > avg) return false;
        for(int i = 0;i < n;i++){
            if(!dp[i]){
                int tmp = matchsticks[i];
                for(int j = i + 1;j < n; j++){
                    if(tmp + matchsticks[j] > avg){
                        continue;
                    }
                    else if(tmp + matchsticks[j] < avg){
                        continue;
                    }
                    else{
                        
                    }
                }
            }
        }

    }
};
int main(){
   
    system("pause:");
    return 0;
}