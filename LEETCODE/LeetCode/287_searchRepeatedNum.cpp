#include<iostream>
#include<vector>
#include<algorithm>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1])
            return nums[i];
        }
        return 0;
    }
};
using namespace std;
int main(){

    system("pause:");
    return 0;
}