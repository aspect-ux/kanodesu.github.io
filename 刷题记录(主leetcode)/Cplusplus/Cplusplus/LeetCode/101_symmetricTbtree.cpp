#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    vector<int> ans1,ans2;
    void dfs1(TreeNode* root){
        if(!root) {
            ans1.push_back(0);
            return;
        }
        ans1.push_back(root->val);
        dfs1(root->left);
        dfs1(root->right);
    }
    void dfs2(TreeNode* root){
        if(!root) {
            ans2.push_back(0);
            return;
        }
        ans2.push_back(root->val);
        dfs2(root->right);
        dfs2(root->left);
    }
    bool isSymmetric(TreeNode* root) {
        dfs1(root);
        dfs2(root);
        return ans1 == ans2;
    }
};
int main(){
   
    system("pause:");
    return 0;
}