#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool compareString(string a,string b) {
        int cnt = 0;
        for (int i = 0; i < a.length(); i ++) {
            if (a[i] != b[i]) cnt ++;
        }
        return cnt<=2;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int m = queries.size(), n = dictionary.size();
        vector<string> ans;
        for (int i = 0; i < m; i ++) {
            int flag = 0;
            for (int j = 0; j < n; j ++) {
                if(compareString(queries[i],dictionary[j])) flag = 1;
            }
            if(flag) {ans.push_back(queries[i]);flag = 0;}
        }
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}