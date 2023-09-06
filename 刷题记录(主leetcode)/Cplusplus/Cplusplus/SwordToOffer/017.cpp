#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(),n = t.length(),l = 0,r = 0,ans = INT_MAX,index1 = 0,index2 = 0;
        unordered_map<char,int> hashs,hasht,sr;
        if (m < n) return "";
        for (auto c : t) hasht[c] ++;
        for (r = 0;r<m;r ++) {
            while(r < m && hasht!=hashs)
            {
                if (hasht.find(s[r]) != hasht.end())
                {
                    hashs[s[r]] ++;
                    sr[s[r]] ++;
                    if (hashs[s[r]] > hasht[s[r]]) hashs[s[r]] = hasht[s[r]];
                }
                r ++;
            }
            r --;
            cout<<r<<'p'<<endl;
            cout<<hashs.size();
            while (hashs == hasht) {
                if (ans > (r - l + 1)) {
                    ans = (r - l + 1);
                    index1 = l,index2 = r - l + 1;
                }
                sr[s[l]] --;
                if(hasht.find(s[l])!=hasht.end() && sr[s[l]] < hasht[s[l]]) {cout<<"!"<<hashs[s[l]];hashs.erase(s[l]);}
                l ++;
                cout<<r<<' '<<l<<endl;
            }
        }
        cout<<index1<<' '<<index2;
        return s.substr(index1,index2);
    }
};