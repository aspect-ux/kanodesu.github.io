#include<iostream>
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
    TreeNode* dfs(TreeNode* root){
       if(!root) return;
        TreeNode* left = dfs(root->left);
        TreeNode* right = dfs(root->right);
        if(left && right){
            ans = max(left->val,right->val);
        }

    }
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        dfs(root);
        return ans;
    }
};
int main(){

    system("pause:");
    return 0;
}