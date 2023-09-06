#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> hash1,hash2;
        int n = words.size(),cnt1 = 0,cnt2 = 0;
        for (int i = 0 ; i < n; i ++) {
            string word = words[i];
            if  (word[0] == word[1]) hash2[word] ++;
            else {
                string tmp = word;
                swap(tmp[0],tmp[1]);
                if (hash1.find(tmp) != hash1.end() && hash1[tmp]) {cnt1 +=2; hash1[word] --;}
                else hash1[word] ++;
            }
        }
        int flag = 0;
        for (auto c : hash2) 
            if (c.second%2){flag = 1;cnt2 += (c.second - 1);}
            else cnt2 += c.second;
        return (cnt1 + cnt2 + flag) * 2;
    }
};