#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// class Solution {
// public:
//     int parseInt(string a){
//         return stoi(a.substr(0,2))*60 + stoi(a.substr(3,3));
//     }
//     int findMinDifference(vector<string>& timePoints) {
//         int n = timePoints.size();
//         vector<int> dp(n,0);
//         for(int i = 0; i < n; i ++){
//             dp[i] = parseInt(timePoints[i]);
//         }
//         int ans = INT32_MAX;
//         for(int i = 0; i < n; i ++){
//             for(int j = i + 1; j < n; j ++){
//                 ans = min(ans,min(abs(dp[i] - dp[j]),24*60-abs(dp[i] - dp[j])));
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int parseInt(string a){
        return stoi(a.substr(0,2))*60 + stoi(a.substr(3,3));
    }
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(),timePoints.end());
        int ans = INT32_MAX;
        for(int i = 0; i < n - 1; i ++){
            ans = min(ans,min(parseInt(timePoints[i+1]) - parseInt(timePoints[i]),24*60 - parseInt(timePoints[i+1]) + parseInt(timePoints[i])));
        }
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}