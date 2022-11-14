#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int n = nums.size(),cnt = 0,flag = 0,ans = 0;
//         for(int i = 0; i < n; i ++){
//             if(nums[i] > nums[i - 1]) {
//                 if(flag == -1)
//                 {
//                     cnt ++;
//                     flag = 1;
//                 }else if(flag == 1){
//                     cnt = 1;
//                 }
//             }
//             ans = max(ans,cnt);
//         }
//     }
// };
// 1 2 5 3 5 3 4
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        int prevdiff = nums[1] - nums[0];
        int ret = prevdiff != 0 ? 2 : 1;
        for (int i = 2; i < n; i++) {
            int diff = nums[i] - nums[i - 1];
            if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
                ret++;
                prevdiff = diff;
            }
        }
        return ret;
    }
};
int main(){
   
    system("pause:");
    return 0;
}