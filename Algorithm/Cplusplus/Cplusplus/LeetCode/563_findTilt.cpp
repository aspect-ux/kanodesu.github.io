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
    void dfs(TreeNode* root,TreeNode* &root1){
        if(!root) return;
        root1->val = abs((root->left?root->left->val:0) - (root->right?root->right->val:0));
        findTilt(root->left);
        findTilt(root->right);
    }
    int findTilt(TreeNode* root) {
        TreeNode* root1 = root;
        dfs(root,root1);
        return root1->val;
    }
};
int main(){
    
    system("pause:");
    return 0;
}