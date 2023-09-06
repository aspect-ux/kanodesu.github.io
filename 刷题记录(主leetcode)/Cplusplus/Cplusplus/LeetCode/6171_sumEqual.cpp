#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> hash;
        for(int i = 1;i < n;i ++){
            if(hash.find(nums[i]+nums[i-1])!=hash.end()){
                return true;
            }
            hash.insert(nums[i-1]+nums[i]);
        }
        return false;
    }
};
int main(){
   
    system("pause:");
    return 0;
}