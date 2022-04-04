#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;

        for(int  i = 0;i<ops.size();i++){
            if(ops[i] == "+"){
                //if(i == 0 || i ==1) s.push_back();
                int a = s.top();
                s.pop();
                int b = s.top();
                s.push(a);
                s.push(a+b);

            }
            else if(ops[i] == "C"){
                s.pop();
            }
            else if(ops[i] == "D"){
                int a = s.top();
                s.push(a*2);
            }
            else{
                s.push(stoi(ops[i]));
            }

        }
        int sum = 0;
        while(!s.empty()){
            sum += s.top();
            s.pop();

        }
        return sum;

    }
};
int main(){
    Solution s;
    vector<string> ops= {"5","-2","4","C","D","9","+","+"};
   cout<<s.calPoints(ops);

    system("pause:");
    return 0;
}