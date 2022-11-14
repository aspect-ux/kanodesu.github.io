#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words.size(),m = words[0].size();
        string tmp;
        unordered_map<string,int> ans;
        for (int i = 0; i < n; i ++) {
            for (int j = 1; j < m; j ++) {
                tmp.push_back(words[i][j] - words[i][j - 1]);
            }
            ans[tmp] ++;
            tmp.resize(0);
        }
        for (auto c : ans) if (c.second == 1) return c.first;
        return "";
    }
};
int main(){
    
    system("pause:");
    return 0;
}