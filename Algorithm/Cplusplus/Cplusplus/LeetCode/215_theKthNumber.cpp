#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[k-1];
    }
};
int main(){

    system("pause:");
    return 0;
}