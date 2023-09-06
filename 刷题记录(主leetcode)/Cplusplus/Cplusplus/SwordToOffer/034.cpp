#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<char,int> hash;
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        for (int i = 0; i < order.size(); i ++) hash[order[i]] = i;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                if (!compareAlienWord(words[i],words[j])) return false;
            }
        }
        return true;
    }
    bool compareAlienWord(string a,string b) {
        int m = a.size(),n = b.size();
        for (int i = 0; i < min(m,n); i ++) {
            int s = hash[a[i]] - hash[b[i]];
            if (s > 0) return true;
            else if (s < 0) return false;
        }
        if (m >= n) return true;
        else return false; 
    }
};