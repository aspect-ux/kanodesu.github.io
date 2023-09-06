#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        string tmp;
        tmp += nums[0] + '0';
        for(int i = 0; i < n; i ++){
            if(nums[i] + 1 == nums[i + 1]){
                continue;
            }
            else{
                if(tmp[0] == nums[i] + '0'){
                    ans.push_back(tmp);
                }else{
                    tmp += "->";
                    tmp += nums[i] + '0';
                    ans.push_back(tmp);
                }
                tmp.clear();
                tmp += nums[i+1] + '0';
            }
        }
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}