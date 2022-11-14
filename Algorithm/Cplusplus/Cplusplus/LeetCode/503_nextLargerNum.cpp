#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(),maxv = 0,now = 0;
        vector<int> ans(n,-1),tmp(2);
        stack<vector<int>> st;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[n - 1]) ans[n - 1] = nums[i];
            while(!st.empty() && st.top()[1] < nums[i + 1]){
                ans[st.top()[0]] = nums[i + 1];
                st.pop();
            }
            if(nums[i] < nums[i + 1])ans[i] = nums[i + 1];
            else st.push({i,nums[i]});
        }
        if(!st.empty())
        for(int i = 0; i < n - 1; i ++){
            while(i < st.top()[0] && !st.empty() && st.top()[1] < nums[i]){
                ans[st.top()[0]] = nums[i];
                st.pop();
            }
        }
        return ans;
    }   
};
int main(){
   
    system("pause:");
    return 0;
}