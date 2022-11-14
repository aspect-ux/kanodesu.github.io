#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
//暴力法超时
/*
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length(),n = p.length();
        vector<int> ans;
        unordered_set<string> hash;
        do{
            hash.insert(p);
        }while(next_permutation(p.begin(),p.end()));
        sort(p.begin(),p.end());
        for(int i = 0 ; i < m - n + 1; i++){
            if(hash.find(s.substr(i,n)) != hash.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        if (sLen < pLen) {
            return vector<int>();
        }
        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);
        for (int i = 0; i < pLen; ++i) {
            ++sCount[s[i] - 'a'];   //
            ++pCount[p[i] - 'a'];  //建立目标索引表
        }
        if (sCount == pCount) {
            ans.emplace_back(0);
        }
        for(int i = 0; i < sLen - pLen; ++i) {
            --sCount[s[i] - 'a'];
            ++sCount[s[i + pLen] - 'a'];

            if (sCount == pCount) {        //每次判断
                ans.emplace_back(i + 1);
            }
        }
        return ans;
    }
};
int main(){

    system("pause:");
    return 0;
}