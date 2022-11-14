#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() / 2;
        unordered_map<int,int> hash;
        for(int i = 0;i < nums.size(); i++){
            hash[nums[i]] ++;
        }
        for(auto x : hash){
            if(x.second > n){
                return x.first;
            }
        }
    }
};
int main(){

    system("pause:");
    return 0;
}