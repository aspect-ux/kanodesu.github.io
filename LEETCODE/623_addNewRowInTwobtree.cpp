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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* p = new TreeNode(val);
        if(depth == 1) {
            p->left = root;
            return p;
        }
        if(depth == 2){
            p->left = root->left;
            root->left = p;
            p->right = root->right;
            root->right = p;
            return p;
        }
        addOneRow(root->left,val,depth - 1);
        addOneRow(root->right,val,depth - 1);
        return nullptr;

    }
};
int main(){


    system("pause:");
    return 0;
}