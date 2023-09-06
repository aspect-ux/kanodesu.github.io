#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
//     "((()))"
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int n = s.length();
        int depth = 0,weight = 1,ans = 0,n1 = 0;
        for(auto c: s)if(c == '(') n1 ++;
        int j = 0;
        for (int i = 0; i < n; i ++)
        {
            if(!st.empty() && s[i] == ')' && s[i - 1] == '(') {
                depth --;
                ans += (1<<depth);
                cout<<ans<<endl;
                if(ans == 3)cout<<'?'<<i<<'?'<<endl;
                st.pop();
                if(j == n1) break;  
            }
            else {
                st.push(s[i]);
                depth ++;
                j ++;
            }
        }
        return ans;
    }
};

int main(){
    
    system("pause:");
    return 0;
}