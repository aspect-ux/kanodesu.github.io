#include<iostream>
#include<vector>
#include<cmath>
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
    vector<vector<string>> ans;
    int flag = 0;
    void dfs(TreeNode* root,int depth){
        if(!root) return;
        dfs(root->left,depth + 1);
        dfs(root->right,depth + 1);
        if(!flag) {
            ans.resize(depth);
            for(int i = 0; i < depth; i ++){
                ans[i].resize(pow(2,depth)-1,"");
            }
            flag = 1;
        }
        ans[depth - 1].push_back(to_string(root->val));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        dfs(root,1);
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}