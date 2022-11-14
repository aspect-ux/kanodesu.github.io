#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

//  0  1  3  5  5
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0,ans = 0,n = nums.size(),minimum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] - sum != 0)
            {
                minimum = nums[i] - sum;
                sum += minimum;    
            }
            else continue;
            ans ++;
            if(nums[n - 1] == sum) return ans;
        }
        return 0;
    }
};

int main(){
   
    system("pause:");
    return 0;
}