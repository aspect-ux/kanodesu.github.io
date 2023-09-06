#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// class Solution {
// public:
//     long long ans = 0;
//     void dfs(int pos,int k,int endPos){
//         if(k>=abs(endPos - pos)){
//             if(k == abs(endPos - pos)){
//                 ans++;
//                 return;
//             }  
//         }
//         else return;
//         dfs(pos + 1,k -1,endPos);
//         dfs(pos - 1,k - 1,endPos);
//     }
//     int numberOfWays(int startPos, int endPos, int k) {
//         dfs(startPos,k,endPos);
//         return (int)(ans%((long long)(10e9+7)));
//     }
// };
// class Solution {
// public:
//     int numberOfWays(int startPos, int endPos, int k) {
//         int left = (k - abs(endPos-startPos))/2 + startPos - endPos,right = 0;
//         if(startPos > endPos){
//             left = endPos - (k - abs(endPos-startPos))/2;
//             right = startPos + (k - abs(endPos-startPos))/2;
//         }
//         else {
//             left = startPos - (k - abs(endPos-startPos))/2;
//             right = endPos + (k - abs(endPos-startPos))/2;
//         }
//         unordered_map<int,int> dp;
//         if((k - abs(endPos-startPos))%2 == 0){
//             dp[left] = 1;
//             dp[right] = 1;
//         }
//         for(int i = left + 1;i<right;i++){
//             dp[i] = dp[i - 1] +
//         }
//         return dp[endPos+1]+dp[endPos-1];

//     }
// };
int main(){
   
    system("pause:");
    return 0;
}