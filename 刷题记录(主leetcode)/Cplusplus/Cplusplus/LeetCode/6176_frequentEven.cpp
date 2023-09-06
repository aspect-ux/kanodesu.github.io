#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> hash;
        sort(nums.begin(),nums.end());
        for(auto c : nums){
            hash[c]++;
        }
        int maxv = 0,ans = -1;
        for(auto h : hash){
            if(h.first%2==0 && h.second > maxv){
                maxv = h.second;
                ans = h.first;
            }
        }
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}