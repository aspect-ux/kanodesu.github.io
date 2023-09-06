#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0,ans = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i+1]){
                cnt ++;
            }
            else{
                nums[i + 1 - cnt] = nums[i + 1];
            }
        }
        return cnt;
    }
};
int main(){


    system("pause:");
    return 0;
}