#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:  // [[1,2],[3],[3],[]]
    vector<vector<int>> ans;
    vector<int> res;
    void dfs(vector<vector<int>>& graph,int i){
        if(i == graph.size() - 1) {
            ans.push_back(res);
            return;
        }
       for(int k = 0;k < graph[i].size(); k++){
           res.push_back(graph[i][k]);
           dfs(graph,graph[i][k]);
           res.pop_back();
       }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        res.push_back(0);
        dfs(graph,0);
        return ans;
    }
};
int main(){

    system("pause:");
    return 0;
}