#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
/*
class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> f(n + 1);
        f[n] = 'z' + 1;
        for (int i = n - 1; i >= 0; i--) f[i] = min(f[i + 1], s[i]);

        string ans;
        stack<char> stk;
        for (int i = 0; i < n; i++) {
            stk.push(s[i]);
            while (!stk.empty() && stk.top() <= f[i + 1]) ans.push_back(stk.top()), stk.pop();
        }
        return ans;
    }
};*/

class Solution {
public:
    string robotWithString(string s) {
        string res,t;
        vector<int> pos(26,-1);
        for (int i = 0; i < s.size(); i ++)
        {
            pos[s[i] - 'a'] = i;
        }
        for (int i = 0,k = 0; i < 26 && k < s.size(); i ++) {
            char c = i + 'a';
            while(t.size() && t.back() <= c){
                res += t.back();
                t.pop_back();
            }
            while (k <= pos[i]) {
                if (s[k] == c) res += c;
                else t += s[k];
                k ++;
            }
        }
        reverse(t.begin(),t.end());
        return res + t;
    }
};
int main(){
    
    system("pause:");
    return 0;
}