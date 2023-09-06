#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mid = (n-1)/2,ans = 0,mid1 = 0,ans1 = 0;
        if(n%2==0) mid1 = mid + 1;
        for(int num : nums){
            if(mid1 == mid + 1) ans1 += abs(num - nums[mid1]);
            ans += abs(num - nums[mid]);
        }
        return n %2 ==0 ? (ans<ans1?ans:ans1): ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}