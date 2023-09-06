#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    unordered_map<int,int> hash; //记录每一行的个数，以此用来参照
    int ans = 0;
    vector<int> status;
    void dfs(vector<vector<int>>& mat,int m,int cols,int n,int pos,int index){
        if(pos == cols) {
            int t = 0;
            for(auto c : hash){
                if(c.second == 0){
                    t++;
                }
            }
            ans = max(ans,t);
            return;
        }

        for(int i = index;i < n;i++){
            //if(status[i]) continue;
            status[i] = 1;
            for(int j = 0;j < m;j++){
                if(mat[j][i]){
                    hash[j]--;
                }
            }
            dfs(mat,m,cols,n,pos + 1,i+1);
            status[i] = 0;
            for(int j = 0;j < m;j++){
                if(mat[j][i]){
                    hash[j]++;
                }
            }

        }
    }
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size(),n = mat[0].size();
        for(int i = 0;i < m;i++){   
             for(int j = 0;j < n;j++){
                hash[i] += mat[i][j];
            }
        }
        status.resize(n,0);
        dfs(mat,m,cols,n,0,0);
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}