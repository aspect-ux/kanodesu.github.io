#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
// class Solution {
// public:
//     bool increasingTriplet(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n,vector<int>(2));
//         unordered_map<int,int> hash;
//         for(int i = 0; i < n; i ++){
//             if(nums[i] > nums[i - 1]){hash[i] = hash[i - 1] + 1;}
//         }
//     }
// };
// 3 4 2 3 1 2 
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        int first = nums[0], second = INT_MAX;
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            if (num > second) {
                return true;
            } else if (num > first) {
                second = num;
            } else {
                first = num;
            }
        }
        return false;
    }
};
int main(){
   
    system("pause:");
    return 0;
}
