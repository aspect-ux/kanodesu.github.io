#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= 0) continue;
            if(nums[i] == n - 1) continue;
            if(nums[i] == n){
                n++;
            }
            else return n;
        }
        return (nums[nums.size()-1]<0?0:nums[nums.size()-1])+1;
    }
};
int main(){
   
    system("pause:");
    return 0;
}