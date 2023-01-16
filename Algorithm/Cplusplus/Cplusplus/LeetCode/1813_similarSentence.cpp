
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool compareSentences(vector<string> a,vector<string> b)
    {
        
        int m = a.size(),n = b.size(),flag = 0;
        vector<string> t;
        for (int i = 0 ; i < n; i ++)
        {
            if (a[i] != b[i] && !flag)
            {
                flag = 1;
                for (int j = i; j < m - n + i; j ++)
                {
                    t.push_back(a[j]);
                }
            }
            t.push_back(b[i]); 
        }
        cout<<t.size();
        if (!flag && a.size() > t.size()) return true;
        for (auto c : t) cout<<c<<endl;
        return t == a;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1,s2;
        int m = sentence1.length(),n = sentence2.length();
        //反序列化
        for (int i = 0; i < m; i ++) 
        {
            string tmp;
            while(i < m && sentence1[i] != ' ') 
            {
                tmp += sentence1[i];
                i ++;
            }
            s1.push_back(tmp);
           
        } 
        for (int i = 0; i < n; i ++) 
        {
            string tmp;
            while(i < n && sentence2[i] != ' ') {
                tmp +=sentence2[i];
                i ++;
            }
            s2.push_back(tmp);
        } 

        //对比
        return compareSentences(s1.size() > s2.size()?s1:s2,s1.size() > s2.size()?s2:s1);
    }
};