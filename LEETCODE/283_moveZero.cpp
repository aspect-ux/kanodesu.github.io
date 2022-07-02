#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(),tail = n - 1,cnt = 0;
         for(int i = 0 ;i < n; i++){
             if(nums[i] == 0)cnt++;
             else{
                nums[i - cnt] = nums[i];
            }
         }
         for(int i = cnt; i >0; i--){
             nums[n - i] = 0;
         }
    }
};
int main(){
    system("pause:");
    return 0;
}