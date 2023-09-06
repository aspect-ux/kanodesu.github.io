#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    void dfs(vector<int> c,int pos,int target,int sum){
        if(pos == c.size()) return;
        if(sum == target) return;
        
        sum += c[pos];
        dfs(c,pos + 1,target,sum);
        sum -= c[pos];
        dfs(c,pos + 1,target,sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
       /* sort(candidates.begin(),candidates.end());
        for(int i = 0; i < candidates.size(); i++){
            if(candidates[i] > target){
                vector<int> c(candidates.begin(),candidates.begin() + i);
                break;
            }
        }*/
        int n = candidates.size(),sum = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            res.clear();
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    sum += candidates[i];
                    res.push_back(candidates[i]);
                }
            }
            if(sum == target)
            ans.push_back(res);
            sum = 0;
        }
        return ans;
    }
};
int main(){

    system("pause:");
    return 0;
}