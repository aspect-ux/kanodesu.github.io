#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    // 1 2 3 4 4 5 6  1 3 3 3 4
    //[1,5,1,1,6,4]  1 1 1 4 5 6   1 4 1 5 1 6
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int k = n / 2 + (n%2?1:0),m = 0;
        sort(nums.begin(),nums.begin()+k,greater<int>());
        sort(nums.begin()+k,nums.end(),greater<int>());
        for(auto c: nums)cout<<c<<endl;
        for(int i = 0,j = 0; i < n;i++){
            if(i%2 == 0) {
                ans.push_back(nums[m]);
                m ++;
            }
            else {
                ans.push_back(nums[k + j]);
                j ++;
            }
        }
        nums = ans;
    }
};
// class Solution {   
// public:
//     void wiggleSort(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> arr = nums;
//         sort(arr.begin(), arr.end());
//         int x = (n + 1) / 2;
//         for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--) {
//             nums[i] = arr[j];
//             if (i + 1 < n) {
//                 nums[i + 1] = arr[k];
//             }
//         }
//     }
// };
// 
int main(){
   
    system("pause:");
    return 0;
}