#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long sum = 0,ans = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
      for(int i = 0; i < nums.size() - 1; i++){
          ans += nums[i];
          sum -= nums[i];
          if(ans >= sum){
              res ++;
          }
      }
      return res;
    }
};
int  main(){

    system("pause:");
    return 0;
}