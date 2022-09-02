#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
//wrong  二分
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size(),j = 0;
        vector<int> ans(n,-1);
        unordered_map<int,int> hash; //用于存储索引
        for(int i = 0;i < n; i++){
            hash[intervals[i][0]] = i; //制表
        }
        sort(intervals.begin(),intervals.end());
        for(int i = 0;i < n; i++){
            auto it = lower_bound(intervals.begin(),intervals.end(),intervals[i][1]);
           
            if(it != intervals.end()){
                ans[i] = hash[it->begin()[0]];
                
            }
        }
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}