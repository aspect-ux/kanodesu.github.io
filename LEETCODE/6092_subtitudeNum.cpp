#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,.> hash;
        vector<int> simple;
       for(int i=0; i<nums.size(); i++){
           hash[nums[i]].push_back(i);
       }
        for(int i=0; i<operations.size(); i++){
            if(hash.find(operations[i][0]) != hash.end()){
                hash[operations[i][0]].push_back(operations[i][1]);
            }    
        }
        for(auto &[x,y]:hash){
            nums[y[0]] = nums[y.size() - 1];
        }
        return nums;
    }
};
int main(){

    system("pause:");
    return 0;
}