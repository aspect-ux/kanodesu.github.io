#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(int i = 0;i< nums.size(); i++){
            hash[nums[i]] ++;
        }
        vector<vector<int>> vec(hash.size(),vector<int>(2));
        vector<int> ans;
        int n = 0;
        for(auto c : hash){
            vec[n++][0] = c.second;
            vec[n][1] = c.first; 
        }
        sort(vec.begin(),vec.end(),[](vector<int>&a,vector<int>& b){return a[0]>b[0];});
        for(int i =0;i < k; i++){
            ans.push_back(vec[i][1]);
        }
        return ans;
    }
};
int main(){
    system("pause:");
    return 0;
}