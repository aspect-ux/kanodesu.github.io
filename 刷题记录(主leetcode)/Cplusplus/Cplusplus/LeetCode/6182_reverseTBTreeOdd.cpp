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
    vector<vector<int>> ans;
    vector<int> res;
    int flag = 0;
    void dfs(TreeNode* root,int deepth){
        if(!root){
            flag = 1;
            return;
        }
        if(deepth%2&&!flag)
        ans.push_back(vector<int>());
        if(deepth%2) ans[deepth/2].push_back(root->val);
        dfs(root->left,deepth+1);
        dfs(root->right,deepth+1);

    }
    TreeNode* dfs1(TreeNode* rootN,TreeNode* rootO,int deepth){
        if(!rootN) return rootN;
        if(deepth%2) {
            rootN->val = ans[deepth/2].front();
            ans[deepth/2].erase(ans[deepth/2].begin());
        }
        dfs1(rootN->left,rootO->left,deepth+1);
        dfs1(rootO->right,rootO->right,deepth+1);
        return rootN;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root->left) return root;
        dfs(root,0);
        TreeNode* root1 = root;
        dfs1(root1,root,0);
        return root1;
    }
};
int main(){
   
    system("pause:");
    return 0;
}