#include<iostream>
#include<vector>
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
    int ans = 0;
    int dfs(TreeNode* root,int depth,int comp){
        if(!root || comp != root->val) return 0;
        return dfs(root->left,depth + 1,comp) + dfs(root->right,depth + 1,comp);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return ans;
        ans = max(dfs(root,0,root->val),ans);
        longestUnivaluePath(root->left);
        longestUnivaluePath(root->right);
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}