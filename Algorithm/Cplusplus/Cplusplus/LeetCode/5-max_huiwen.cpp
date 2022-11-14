#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
/*
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};

*/
//https://leetcode-cn.com/problems/longest-palindromic-substring/solution/
// 时间复杂度太大

class Solution {
public:
    string longestPalindrome(string s) {
          int max = 0,m,n;
          bool dp[s.length()-1][s.length()-1];
          memset(dp,false,sizeof(dp));
         for(int i = 0; i<s.length(); i++){
             for(int j = 1; j <= s.length(); j++){
                string temp1 = s.substr(i,j);      //截取子串
                reverse(temp1.begin(),temp1.end());//颠倒            
                if(s.substr(i,j) == temp1){        //比较是否为回文
                dp[i][j] = true;
                    if(max<temp1.length())
                       {
                            max = temp1.length();
                            m = i;
                            n = j;
                       }
                }     
             }
         }
         if(s.length() == 1) return s;
         return s.substr(m,n);

    } 
};





int main(){
    Solution s;

    cout<<s.longestPalindrome("abcba");
    system("pause:");
    return 0;
}

