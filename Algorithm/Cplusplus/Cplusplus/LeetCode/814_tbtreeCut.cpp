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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return root;
        //1th
        //后序遍历
        root->left = pruneTree(root->left);
        //2th 叶子（左）深搜阶段是左叶
        //这里一般      回溯阶段是根节点，与最后的return对应
        root->right = pruneTree(root->right);
        if(!root->left && !root->right && root->val == 0){
            return nullptr;
        }
        //3thpart 叶子（右） 
        return root;

        //return 回溯，第一次回到最左边叶子结点的根节点 
    }
};

int main(){


    system("pause:");
    return 0;
}