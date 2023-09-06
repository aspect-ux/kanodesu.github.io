#include<iostream>
#include<vector>
using namespace std;
// class Solution {
// public:
//     vector<int> ans;
//     vector<int> status;
//     int res = 0;
//     void dfs(int i,int n)
//     {
//         if(i == n + 1){
//             res ++;
//             return;
//         }
//         if(i % (ans.size())&&(ans.size()) % i) return;
//         for(int j = i; j < n + 1; j ++){
//             if(status[j]) continue;
//             status[j] = 1;
//             ans.push_back(j);
//             dfs(j + 1,n);
//             ans.pop_back();
//             status[j] = 0;
//         }
//     }
//     int countArrangement(int n) {
//         ans.resize(1);
//         status.resize(n+1,0);
//         dfs(1,n);
//         return res;
//     }
// };
class Solution {
public:
    vector<vector<int>> match;
    vector<int> vis;
    int num;
    void backtrack(int index, int n) {
        if (index == n + 1) {
            num++;
            return;
        }
        for (auto &x : match[index]) {
            if (!vis[x]) {
                vis[x] = true;
                backtrack(index + 1, n);
                vis[x] = false;
            }
        }
    }
    int countArrangement(int n) {
        vis.resize(n + 1);
        match.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i % j == 0 || j % i == 0) {
                    match[i].push_back(j);
                }
            }
        }
        backtrack(1, n);
        return num;
    }
};


int main(){
    
    system("pause:");
    return 0;
}