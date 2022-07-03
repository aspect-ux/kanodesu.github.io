#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        vector<int> ans;
        for(int n : nums){
            hash[n]++;
        }
        for(auto &[x,y]:hash){
            if(y>(nums.size()/3)){
                ans.push_back(x);
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}