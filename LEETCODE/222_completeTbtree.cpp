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
    void dfs(int& ans,TreeNode* root){
        if(!root){
            ans = 0;
            return;
        }
        if(root->left == nullptr){
            return;
        }
        if(root->left != nullptr && root->right == nullptr){
            ans += 1;
            return ;
        }
        if(root->right){
            ans += 2;
            dfs(ans,root->left);
            dfs(ans,root->right);
        }
        
    }
    int countNodes(TreeNode* root) {
        // i  i/2  2*i 2*i+1
        int ans = 1;
        dfs(ans,root);
        return ans;

    }
};
int main(){


    system("pause:");
    return 0;
}