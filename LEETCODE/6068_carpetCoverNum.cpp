#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        //首先要找到最大值以此来分配空间
        int maxv = 0;
        for(int i= 0; i < tiles.size(); i++){
            maxv = max(tiles[i][1],maxv);
        }
        vector<int> dp(maxv + 1,0);
        int cnt = 0,ans = 0;
        for(int i = 0;i < tiles.size(); i++){
           for(int j = tiles[i][0]; j <= tiles[i][1]; j++){
               dp[j] = 1;
           }
        }
        if(dp.size() < carpetLen){
            carpetLen = dp.size() - 1;
        }
        for(int i = 1;i <= carpetLen; i++){
            //如果到底
           if(dp[i]){
               cnt ++;
           }
        }
        if(dp.size() < carpetLen) return cnt;
        ans = max(ans,cnt);
        for(int j = carpetLen + 1; j < dp.size(); j++){
            if(dp[j]){
                cnt = dp[j - carpetLen]?cnt:(cnt+1);
                ans = max(ans,cnt);
            }
            else  cnt = dp[j - carpetLen]?(cnt - 1):cnt;
        }
        return max(ans,cnt);
    }
};
/*
int cmp(int x,int y){
    return x > y ? x:y; 
}
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
         //首先要找到最大值以此来分配空间
        int maxv = 0;
        for(int i= 0; i < tiles.size(); i++){
            maxv = max(tiles[i][1],maxv);
        }
        vector<int> dp(maxv + 1,0);


        //先找长度最长的到时候直接定位，不行就找第二长的
        vector<int> table(tiles.size());
        for(int i = 0; i < tiles.size(); i++){
            table[i] = tiles[i][1] - tiles[i][0] + 1;
        }
        sort(table.begin(),table.end(),cmp);

        for(int i = 0; i < dp.size(); i++){

        }
    }
};*/
int main(){
    vector<vector<int>> tiles={{10,11},{1,1}};//{{1,5},{10,11},{12,18},{20,25},{30,32}};
    int carpetLen = 2;
    Solution s;
    cout<<s.maximumWhiteTiles(tiles,carpetLen);
    system("pause:");
    return 0;
    
}