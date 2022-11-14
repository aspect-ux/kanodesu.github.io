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
    bool dfs(TreeNode* root, TreeNode* subRoot, TreeNode* keep){
        if(!root&&!subRoot) return true;
        if(!root||!subRoot) {
            subRoot = keep;
        }
        if(root->val == subRoot->val)
        {
            return dfs(root->left,subRoot->left,keep) &&
            dfs(root->right,subRoot->right,keep);
        }else{
            subRoot = keep;
            return dfs(root->left,keep,keep) &&
            dfs(root->right,keep,keep);   
        }
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root,subRoot,subRoot);
    }
};
int main(){
    
    system("pause:");
    return 0;
}