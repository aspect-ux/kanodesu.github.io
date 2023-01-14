#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        stack<char> st;
        string ans;
        unordered_map<string,string> hash;
        int n = s.length();
        for (auto c : knowledge) hash[c[0]] = c[1];
        for (int i = 0 ; i < n; i ++){
            char c = s[i];
            if (st.size() && st.top() == '(' && c == ')')
            {
                st.pop();
            }
            else if (c == '(') 
            {
                st.push(c);
                string tmp;
                int j = i + 1;
                while(s[j] != ')') {
                    tmp += s[j++];
                }
                ans += ((hash.find(tmp)==hash.end())?"?":hash[tmp]);
            }
            else {
                ans+=c;
            }
        }
        return ans;
    }
};