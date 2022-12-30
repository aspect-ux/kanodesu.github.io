#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//字典树
class TrieNode {
    TrieNode* children[26];
public:
    int count;
    TrieNode()
    {
        for (int i = 0; i < 26; i ++) {
            children[i] = NULL;
        }
        count = 0;
    }
    TrieNode* get(char c) {
        if (children[c - 'a'] == NULL) {
            children[c - 'a'] = new TrieNode();
            count ++;
        }
        return children[c - 'a'];
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0,n = words.size();
        unordered_map<TrieNode*,int> nodes;
        TrieNode* trie = new TrieNode();
        for (int i = 0; i < n; i ++) {
            string word = words[i];
            TrieNode* cur = trie;
            for (int j = word.length() - 1; j >= 0; j --) {
                cur = cur->get(word[j]);
            }
            nodes[cur] = i;
        }
        for (auto &[node,index] : nodes) {
            if (node->count == 0) {
                ans += words[index].length() + 1;
            }
        }
        return ans;
    }
};