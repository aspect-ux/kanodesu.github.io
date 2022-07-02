#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while(nums.size()!=1){
            vector<int> newNums(nums.size()/2);
            for(int i = 0; i < nums.size() / 2;i++){   
                if(i%2){
                    newNums[i] = max(nums[2*i],nums[2*i+1]);
                }
                else {
                    newNums[i] = min(nums[2*i],nums[2*i+1]);
                }
            }
            nums = newNums;
        }
        return nums[0];
    }
};
int main(){
    system("pause:");
    return 0;
}