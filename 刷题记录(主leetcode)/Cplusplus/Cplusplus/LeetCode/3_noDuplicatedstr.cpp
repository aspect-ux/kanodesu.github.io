#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
   int lengthOfLongestSubstring(string s) {
        int length = s.length();
        if(length == 0) return 0;
        int dp[length];
        int ans = 1;
        dp[0] = 1;
        for(int i=1;i<length;++i)
        {
            int res = s.find(s[i], i-dp[i-1]);
            if(res >= i)
                dp[i] = dp[i-1] + 1;
            else if(res < i )
                dp[i] = i-res;
            ans = max(ans, dp[i]);                
        }
        return ans;
    }
};  
/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int n = 1,ans = 0;
        for(int i = 0; i < s.length(); i++){
            if(hash.find(s[i]) != hash.end()){
                auto it = hash.find(s[i]);
                n = hash[s[i - 1]] - (*it).second + 1;
                hash.erase(hash.begin(),++it);  
            }
            hash.insert({s[i],n++});
            ans = max(ans,n - 1);     
        }
         return ans ;
    }
};*/

int main(){
    Solution s;
    string a ="abcabcbb";
    cout<<s.lengthOfLongestSubstring(a);
   
    //system("pause:");
    return 0;
}