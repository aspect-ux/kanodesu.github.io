#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int start,end,n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1] || a[1] == b[1] && a[0] < b[0];});
        start = intervals[0][0];
        for(int i = 0;i < n - 1; i++){
            end = intervals[i][1] >= intervals[i + 1][1] ?intervals[i][1]:(intervals[i][1] < intervals[i+1][1]?intervals[i][1]:intervals[i+1][1]);
            start = intervals[i][0] < intervals[i+1][0]? start : intervals[i+1][0];
            if(intervals[i][1] >= intervals[i + 1][0] && intervals[i][1] < intervals[i+1][1]){
                continue;
            }
            else{
                ans.push_back({start,end});
            }
        }
        if(intervals[n-2][1]>intervals[n-1][1] && intervals[n-2][0] < intervals[n-1][0]){
            ans.push_back({intervals[n-2][0],intervals[n-1][1]});
        }
        else ans.push_back({start,intervals[n-1][1]});
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}