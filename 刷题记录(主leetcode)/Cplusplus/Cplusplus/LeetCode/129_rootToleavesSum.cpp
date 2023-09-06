#include<iostream>
#include<queue>
#include<unordered_map>
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
    int dfs(TreeNode* root,int b){
        if(!root) return 0;
        if(!root->left&&!root->right){
            return b*10+root->val;
        }
        return dfs(root->left,b*10+root->val)+dfs(root->right,b*10+root->val);
        
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};
int main(){

    system("pause:");
    return 0;
}