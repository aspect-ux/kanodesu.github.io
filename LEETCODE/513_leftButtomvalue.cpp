#include<iostream>
#include<unordered_map>
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
    int hi = 0;
    int value = 0;
    void dfs(TreeNode* root,int ans){
         if(!root){
            return;
        }
        dfs(root->left,ans + 1);
        if(ans >= hi){
            hi = ans;
            value = root->val;
        }
        dfs(root->right,ans + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
       dfs(root,0);
       return value;
    }
};
int main(){

    system("pause:");
    return 0;
}