#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int temp = abs(nums[0]),close = 0;
        for(int i = 1;i < nums.size(); i++){
            if(temp > abs(nums[i] - 0)){
                close = i;
                temp = abs(nums[i] - 0);
            }
            if(temp == abs(nums[i] - 0)){
                if(nums[i] > nums[close])
                close = i;
            }
        }
        return nums[close];
    }
};
int main(){


    system("pause:");
    return 
}