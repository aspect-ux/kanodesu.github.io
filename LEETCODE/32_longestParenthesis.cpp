#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
/*
class Solution {
private:
    int n = 0;
    int marginr = 0;
    int alarm = 0;
public:
    void dfs(string s,int pos,stack<char>& st,int& ans,vector<int> &res){
        if(pos == s.length()) {
            if(!st.empty()) {//栈不为空，只有可能是顺括号多了，这时只用减去多余的就行
            //但是还有一种情况，前面的并不是成对消去，所以这时候要记录多余的）
          res.push_back((ans+alarm -st.size())*2);
          return;
            }
            res.push_back(ans*2);
            return;      
            //栈为空,即 
        }
        if(s[pos] == '(')                   //无论空否（
        {
            st.push(s[pos]);
            alarm++;
        }
        else if(!st.empty() &&s[pos] == ')') //非空且有）
        {
         
            char c = st.top();
            if(c == '('){
                st.pop();
                if(!alarm)
                ans+= 2;
                marginr ++;
            }
        }
        else if(st.empty() && s[pos] ==')'){ //空且） 有两种不合法，一种是反括号多了另一种是顺括号多了
            //不合法1,而由于顺括号只有当结束时才知道多没多
            marginr ++;
            res.push_back(ans);
            ans = 0;
        }

        dfs(s,pos+1,st,ans,res);
        

    }
    int longestValidParentheses(string s) {
        stack<char> st;
        vector<int> res;
        int ans = 0;
        dfs(s,0,st,ans,res);
        int max = 0;
        for(int  i = 0;i <res.size(); i++){
            if(max < res[i]){
                max = res[i];
            }
        }
        return max;

    }
};*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int dp[s.length()],ans = 0;
        memset(dp,0,sizeof(dp));//dp用来记录当前位置的有效长度,那么有效值一定是以）结尾
        for(int i = 1;i < s.length(); i++){
            //如果（ ）
            if(s[i] == ')'){
                if(s[i - 1] == '('){
                    dp[i] = 2 + (i>=2 ? dp[i - 2]:0);
                }
                 //如果）） i - dp[i - 1] - 1 是对称位置
                else if( i - dp[i-1] >0 && dp[i - dp[i - 1] - 1] == '('){
                    dp[i] == dp[i - 1]  + 2 +((i - dp[i - 1])>=2 ?dp[i - dp[i - 1] - 2] : 0); 
            }
            ans = max(ans, dp[i]);
            }
           
        }
        return ans;


    }
};
int main(){
    Solution s;
    cout<<s.longestValidParentheses("()(())");
	
	system("pause:");
	return 0;
} 