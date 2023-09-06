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
    int flag = 0,minv = INT32_MAX;
    TreeNode* dfs(TreeNode* root,int key){
        if(!root) return root;
        dfs(root->left,key);
        dfs(root->right,key);
        if(root->left && root->left->val == key ||root->right && root->right->val == key) return root; 
        return root;
    }
    void dfs1(TreeNode* root,TreeNode* &r3){
        if(!root) return;
        dfs1(root->left,r3);
        dfs1(root->right,r3);
        if(minv > root->val){
            r3 = root;
            minv = root->val;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* r1 = dfs(root,key),*r2 = (root->left&&(root->left->val == key)?root->left:root->right),*r3 = nullptr,*r4;
        dfs1(r2,r3);
        if(!r3){
            if(r1->left && r1->left->val == key){
                
            }
        }

    }
};
int main(){
    
    system("pause:");
    return 0;
}