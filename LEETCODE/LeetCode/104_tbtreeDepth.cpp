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
    int temp = 0;
    int dfs(TreeNode* root,int ans){
        if(!root){
             temp = max(temp,ans);
             ans = 0;
             return temp;
        }
        ans ++;
        dfs(root->left,ans);
        dfs(root->right,ans);
        return temp;
    }
    int maxDepth(TreeNode* root) {
        int ans = 0;
        return dfs(root,ans);
    }
};
int main(){


    system("pause:");
    return 0;
}