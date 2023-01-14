#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int,int> hash1,hash2;
    bool dfs(string a,string b)
    {

    }
    bool isItPossible(string word1, string word2) {
        for (auto c : word1) hash1[c]++;
        for (auto c : word2) hash2[c] ++;
        if (hash1.size() == hash2.size()) return true;
        while (hash1.size() != hash2.size()) {

        }
    }
};