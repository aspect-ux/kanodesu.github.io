#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         int n = nums.size(),first = nums[0],second = INT32_MIN,flag = 0;
//         for(int i = 1; i < n; i ++){
//             if(nums[i] < second && nums[i] > first && !flag){
//                 return true;
//             }else if(nums[i] > first){
//                 second = nums[i];
//                 flag = 0;
//             }else {
//                 //if(i == n - 2) return false;
//                 for(int j = n - 1; j >= i + 1; j--)
//                     if(nums[j] < second && nums[j] > first)
//                         return true;
//                 first = nums[i];
//                 flag = 1;
//             }
//         }
//         return false;
//     }
// };
// 3 1 4 2   4 
//
// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         vector<int> stk;
//         int n = nums.size();
//         int l = -1e9;
//         for(int i = n - 1; i >= 0; i--) {
//             if (nums[i] < l) return true;
//             while(stk.size() && stk.back() < nums[i]) {
//                 l = stk.back();
//                 stk.pop_back();
//             }
//             stk.push_back(nums[i]);
//         }
//         return false;
//     }
// };
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size(),first = nums[0],third = INT32_MAX,flag = 0;
        for(int i = 1,j = n - 1; i < n; i ++){
            while(nums[j]<=nums[i]){
                j --;
                if(j < 0) break;
                if(nums[j] > nums[i]){
                    flag = 1;
                    third = nums[j];
                }
            }if(j < 0)break;
            if(nums[i] > third && flag){
                return true;
            }else if(nums[i] < first){
                first = nums[i];
                flag = 0;
            } 
        }
        return false;
    }
};
int main(){
   
    system("pause:");
    return 0;
}
