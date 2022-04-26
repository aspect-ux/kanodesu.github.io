#include<iostream>
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
    TreeNode* p;
    void flatten(TreeNode* root) {
     if(!root)return;
     flatten(root->right); //倒着来
     flatten(root->left);
     //后序遍历
     root->right = p;
     root->left = nullptr;
     p = root;
    }
};
int main(){

    system("pause:");
    return 0;
}