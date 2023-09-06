#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0,flag = 0,keep = 0;
        for(int n : nums){
            if(n == 1){
                ans ++;
                keep = max(keep,ans);
            }
            else ans = 0;
        }
        return keep;
    }
};
int main(){
   
    system("pause:");
    return 0;
}