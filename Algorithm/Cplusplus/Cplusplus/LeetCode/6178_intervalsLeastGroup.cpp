#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>&b){return a[0]<b[0] || (a[0]==b[0])&&(a[1]<b[1]);});
        int n = intervals.size(),end = 0,ans = 0;
        vector<bool> status(n,false);
        for(int i = 0; i < n; i++){
            if(status[i]) continue;
            end = intervals[i][1];
            status[i] = true;
            for(int j = 0; j < n; j++){
                if(end < intervals[j][0]) {
                    end = intervals[j][1];
                    status[j] = true;
                }
            }
            ans ++;
        }
        return ans;
    }
};
class Solution {
 public:
    int minGroups(vector<vector<int>>& intervals) {
        
    }
};
int main(){
   
    system("pause:");
    return 0;
}