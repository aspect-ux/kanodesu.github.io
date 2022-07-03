#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
class Solution { //要预防
public:
    int tmp;
    bool dfs(string s, vector<string>& wordDict,int start,int i,unordered_set<string> hash){
        if(start == s.length()) return true;
        if(start<s.length() && i == s.length()) return false;
        if(hash.find(s.substr(start,i + 1 - start)) != hash.end()){ //找到
                tmp = start;
                start = i + 1;
        }
        if(dfs(s,wordDict,start,i + 1,hash)){
            return true;
        }
        else{
            start = tmp;
            return dfs(s,wordDict,start,i + 1,hash);
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash;
        for(int i = 0;i < wordDict.size(); i++){
            hash.insert(wordDict[i]);
        }
        return dfs(s,wordDict,0,0,hash);
    }
};

int main(){

    system("pause:");
    return 0;
}