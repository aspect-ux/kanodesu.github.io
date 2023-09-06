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
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        convertBST(root->right);
        convertBST(root->left);
        root->val += ans;
        ans += root->val;
        return root;
    }
};
int main(){
    
    system("pause:");
    return 0;
}