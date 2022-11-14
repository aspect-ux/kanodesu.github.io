#include<iostream>
#include<vector>
using namespace std;
// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int n = intervals.size(),flag = 0,flag1 = 0;
//         vector<vector<int>> ans;
//         for(int i = 0; i < n - 1; i++){
//             if(i == 3)cout<<"?"<<endl;
//             ans.push_back({intervals[i][0],intervals[i][1]});
//             if(intervals[i][0] <= newInterval[0] && newInterval[0] < intervals[i+1][0] && !flag)
//             {
//                 if(newInterval[0] > intervals[i][1]){
//                     flag = 1;
//                     //新开头
//                     if(newInterval[1] < intervals[i+1][0]){
//                         ans.push_back({newInterval[0],newInterval[1]});
//                     }
//                     else if(newInterval[1] >= intervals[i+1][0]){
//                         flag1 = 1;
//                         while(newInterval[1] >= intervals[i+1][0] || newInterval[1] > intervals[i+1][1]){
//                             if(newInterval[1] <= intervals[i+1][1]){
//                                 ans.push_back({newInterval[0],intervals[i+1][1]});
//                                 i++;
//                                 break;
//                             }
//                             i++;
//                             break;
//                             if(i == n - 1) {
//                                 ans.push_back({newInterval[0],intervals[n-1][1]});
//                                 flag1 = 1;
//                                 break;
//                             }
//                         }
//                     }
//                 }
//                 if(newInterval[0] <= intervals[i][1]){
//                     if(newInterval[1] < intervals[i][1]){
//                         flag = 1;
//                         break;
//                     }
//                     else if(newInterval[1] < intervals[i+1][0]){
//                         ans[i][1] = newInterval[1];
//                     }
//                     else if(newInterval[1] >= intervals[i+1][0]){
//                         flag1 = 1;
//                         while(i <= n - 1 &&(newInterval[1] >= intervals[i+1][0] || newInterval[1] > intervals[i+1][1])){
//                             cout<<i<<endl;
//                             if(newInterval[1] <= intervals[i+1][1]){
//                                 cout<<"00"<<ans.size()<<endl;
//                                 ans[ans.size()-1][1] = intervals[i+1][1];
//                                 i++;
//                                 break;
//                             }
//                             //cout<<1<<endl;
//                             //cout<<i<<endl;
//                             i++;
//                             if(i == n - 1) {
//                                 ans.push_back({newInterval[0],intervals[n-1][1]});
//                                 flag1 = 1;
//                                 break;
//                             }
//                             //cout<<i<<endl;
//                         }
//                     }
//                 }
//             }
//         }
//         if(n == 0) ans.push_back({newInterval[0],newInterval[1]});
//         else if(n == 1){
//             if(newInterval[0]>intervals[0][1]){
//                 ans.push_back({intervals[0][0],intervals[0][1]});
//                 ans.push_back({newInterval[0],newInterval[1]});
//             }
//             else if(newInterval[1]<intervals[0][0]){
//                 ans.push_back({newInterval[0],newInterval[1]});
//                 ans.push_back({intervals[0][0],intervals[0][1]});
//             }
//             else{
//                 ans.push_back({min(newInterval[0],intervals[0][0]),max(newInterval[1],intervals[0][1])});
//             }
//         }
//         else if(!flag1) ans.push_back({intervals[n-1][0],intervals[n-1][1]});
//         return ans;
//     }
// };
int main(){
   
    system("pause:");
    return 0;
}