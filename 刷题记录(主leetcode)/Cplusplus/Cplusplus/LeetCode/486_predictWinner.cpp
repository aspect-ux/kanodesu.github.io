#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size(),sum = 0;
        vector<int> dp1(n),dp1(n + 1);
        for (int i = 0; i < n; i ++){
            sum += nums[i];
        }
    }
};
int main(){
    
    system("pause:");
    return 0;
}