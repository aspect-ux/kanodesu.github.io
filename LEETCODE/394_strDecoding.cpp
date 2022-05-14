#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        string temp,ans = "";
        int num = 0, n = 0;
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '['){
                temp.clear();
                st.push(s[i]);
                while(!st.empty()){
                    i++;
                    if(i == s.length() - 1) break;
                    if(s[i] == ']'){
                         st.pop();
                         if(st.empty()) break;
                    }
                    temp.push_back(s[i]);            
                }
                //将每轮的temp根据次数放入ans
                for(int k = 0;k < num; k++){
                    ans += temp;
                }
                num = 0;
                n = 0;
            }
            else if(s[i] >= 97 && s[i] <= 122){
                ans += s[i];
            }
            else{
                num = num*10 + s[i] - 48;
            }     
        }
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.decodeString("3[a]2[bc]");
    system("pause:");
    return 0;
}