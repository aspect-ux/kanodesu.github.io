#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long compute(int a){
        return (a+1)*a/2;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        int cnt = 0;
        long long ans = 0;
        for(auto c : nums){
            if(c == 0){
                cnt ++;
            }
            else{
                ans += compute(cnt);
                cnt = 0;
            }
        }
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}