#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        ans = strs[0];
        for(int i = 1 ;i < n;i ++){
            string tmp = "";
            for(int j = 0;j < ans.size();j ++){
                if(j >= strs[i].size()){
                    break;
                }
                if(ans[j] == strs[i][j]){
                    tmp.push_back(ans[j]);
                }
                else{
                    break;
                }
            }
            ans = tmp;
        }
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}