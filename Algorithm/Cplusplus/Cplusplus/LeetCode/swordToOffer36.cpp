#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    void caculate(string s,stack<int>&st){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if(s == "+")
        st.push(a+b);
        else if(s == "-"){
            st.push(b-a);
        }
        else if(s == "*"){
            st.push(a*b);
        }
        else st.push(b/a);
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
               caculate(s,st);
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};
int main(){
    Solution s;
    
    system("pause:");
    return 0;
}