#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> hash;
        vector<string> ans;
        if(s.length()<=10) return {};
        for(int i = 0;i < s.size();i++){
            hash[s.substr(i,10)] ++; 
        }
        for(auto c:hash) 
        if(c.second > 1) ans.push_back(c.first);
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}