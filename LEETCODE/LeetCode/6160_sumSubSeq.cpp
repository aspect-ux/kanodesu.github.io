#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = queries.size();
        vector<int> ans;
        vector<long long> hash(n+1,0);
        sort(nums.begin(),nums.end());
        sort(queries.begin(),queries.end());
        for(int i = 1;i < nums.size();i++){
            hash[i] = hash[i - 1] + nums[i];
        }
        int j = 0;
        for(int i = 0;i < queries.size();i++){
            while(j!=n+1&&queries[i]>hash[j]){
                j++;   
            }
            if(j == n+1)
            {
                ans.push_back(0);
                break;
            }
            if(queries[i]<hash[j]) ans.push_back(j - 1);
            else
            ans.push_back(j);
        }
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}