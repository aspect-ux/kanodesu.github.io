#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> hash;
        int ans = 0;
        for(auto c:nums) hash.insert(c);
        for(int i = 1;i < nums.size() - 1;i++){
            if(hash.find(nums[i]+diff)!=hash.end()&&hash.find(nums[i]-diff)!=hash.end())
            ans ++;
        }
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}