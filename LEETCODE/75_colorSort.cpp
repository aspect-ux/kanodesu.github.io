#include<iostream>
#include<vector>
using namespace std;
//主要考察排序，不用sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0,right = nums.size() - 1;
        for(int i = 0, j = 0; i < nums.size(); i++, j++){
            for(int k = i+1; k < nums.size(); k++){
                if(nums[i] > nums[k]){
                    int temp = nums[i];
                    nums[i] = nums[k];
                    nums[k] = temp;
                }
            }
        }
        
    }
};
int main(){


    system("pause:");
    return 0;
}