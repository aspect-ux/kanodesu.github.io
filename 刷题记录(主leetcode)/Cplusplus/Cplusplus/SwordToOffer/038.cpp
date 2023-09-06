#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i --) {
            while (st.size() && temperatures[i] >= temperatures[st.top()])
            {
                st.pop();
            }
            if (st.size() == 0) ans[i] = 0;
            else ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};