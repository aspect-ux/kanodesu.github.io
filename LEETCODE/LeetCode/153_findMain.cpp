#include<iostream>
using namespace std;
#include<vector>
// 3 4 5 0 1 2
// 0 1 2 3 4 5
// 5 0 1 2 3 4
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0,r = nums.size()-1,m;
        while(l<r){
            m = (l+r)/2;
            if(nums[m] < nums[r]){//意味着旋转没过一半，那么最小值在左边
                r = m - 1;
            }
            else{
                //当旋转过一半
                l = m + 1;
            }
        }
        return nums[l];
    }
};
int main(){
   
    system("pause:");
    return 0;
}