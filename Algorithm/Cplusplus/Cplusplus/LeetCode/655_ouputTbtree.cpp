#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<string>> dp;
    vector<vector<string>> printTree(TreeNode* root) {
        if(!root) return dp;
        queue<TreeNode*> qu;
        qu.push(root);
        int m = 0;
        while(!qu.empty()){
            int n = qu.size();
            dp.push_back(vector<string>());
            for(int i = 0; i< n; i++){
                TreeNode* tmp = qu.front();
                dp[m].push_back(to_string(tmp->val));
                if(tmp->left) qu.push(tmp->left);
                if(tmp->right) qu.push(tmp->right);
                qu.pop();
            }
            m++;

        }
        return dp;
    }
};
int main(){

    system("pause:");
    return 0;
}