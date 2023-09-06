#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> stNum;
        for (int i = 0; i < n; i ++) {
            if (tokens[i] == "-" || tokens[i] == "+" || tokens[i] == "/" || tokens[i] == "*"){
                int op1 = stNum.top();
                stNum.pop();
                int op2 = stNum.top();
                stNum.pop();
                int op3 = 0;
                if (tokens[i] == "+") {
                    op3 = op1 + op2;
                }else if (tokens[i] == "-") {
                    op3 = op2 - op1;
                }else if (tokens[i] == "/") {
                    op3 = op2 / op1;
                }else op3 = op1 * op2;
                stNum.push(op3);
            } 
            else stNum.push(atoi(tokens[i].c_str()));
        }
        return stNum.top();
    }
};