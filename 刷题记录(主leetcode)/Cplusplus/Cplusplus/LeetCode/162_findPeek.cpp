#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(),l = 0, r = n - 1,mid;
        while(l < r){
            mid = (r - l)/2 + l;
            if(nums[mid] > nums[mid + 1]) r = mid;
            else l = mid + 1;
         }
         return l;
    }
    // 6 5 4 5 1 2
};
int main(){
    
    system("pause:");
    return 0;
}