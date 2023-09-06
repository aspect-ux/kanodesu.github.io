#include<iostream>
#include<vector>
using namespace std;
class Solution {
public: //判断是否为三角形，只需判断较小的两边之和大于第三遍就可，排序过后，就好弄了
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(),ans = 0;
        for(int i = 0; i < n - 2; i ++){
            for(int j = i+1 ; j < n - 1; j++){
                for(int k = j + 1; k < n; k++ )
                if(nums[i] + nums[j] > nums[k]  && abs(nums[i] - nums[j]) < nums[k]){
                    ans ++;
                }
            }
        }
        return ans;
    }
};
int main(){
    system("pause:");
    return 0;
}