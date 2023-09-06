#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
/*  wrong
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int dp[100];
        memset(dp,0,sizeof(dp));
        int n = 0,i,j,k;
        for(i = 0;i < strs.size();i ++){                    //pivot
            if(dp[i]) continue;                                 //如果这个基准已经被使用过了，就跳过
            ans.push_back(vector<string>({strs[i]}));
            if(i == strs.size() - 1) break;
            for(k = i + 1; k < strs.size(); k++){               //next
                for(j = 0; j < strs[k].length(); j ++){         //find
                if(strs[i].find(strs[k][j]) > strs[i].length()){ //在基准字符串中没找到指定的字符
                    break;                                           //那么此时就没有必要找了，直接进入下一个
                }
                }
                if(j == strs[i].length()){ //找到了相同的,就放进去
                    ans[n].push_back(strs[k]);
                    dp[k] = 1;
                }

            }
            n++;
        }
        return ans;
    }
};*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,vector<string>> M;
        for(int i=0;i<strs.size();i++){
            string key=strs[i];
            sort(key.begin(),key.end());
            M[key].push_back(strs[i]);
        }
        for(auto ite=M.begin();ite!=M.end();ite++)
            res.push_back(ite->second);
        return res;
    }
};
int main(){

    system("pause:");
    return 0;
}