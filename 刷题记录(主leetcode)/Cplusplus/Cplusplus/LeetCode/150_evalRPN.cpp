#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    void getOp(int &op1,int &op2,stack<int>&st){
        op1 = st.top();
        st.pop();
        op2 = st.top();
        st.pop();
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a,op1,op2;
        for(string s : tokens){
            if(s.length() == 1 && (s[0] == '+'||s[0] == '-'||s[0]=='/'||s[0]=='*')){
                if(s[0] == '+'){
                    getOp(op1,op2,st);
                    st.push(op1 + op2);
                }
                else if(s[0] == '-'){
                    getOp(op1,op2,st);
                    st.push(op1 - op2);
                }
                else if(s[0]=='/'){
                    getOp(op1,op2,st);
                    st.push(op1 / op2);
                }
                else if(s[0]=='*'){
                    getOp(op1,op2,st);
                    st.push(op1 * op2);
                } 
            }
            else{
                a = stoi(s);
                st.push(a);
            }
        }
        return st.top();
    }
};
int main(){
   
    system("pause:");
    return 0;
}