#include<iostream>
#include<vector>
using namespace std;
//要求使用logN的算法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0;i < nums.size(); i++){
            if(nums[i] >= target){
                return i;
            }
        }
    
    }
};
int main(){
    system("pause:");
    return 0;

}