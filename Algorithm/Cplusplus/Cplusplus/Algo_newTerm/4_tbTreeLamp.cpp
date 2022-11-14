#include<iostream>
#include<vector>
using namespace std;
// 开关 1：切换当前节点的灯的状态；
// 开关 2：切换 以当前节点为根 的子树中，所有节点上的灯的状态，；
// 开关 3：切换 当前节点及其左右子节点（若存在的话） 上的灯的状态；
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> dp;
    int cnt = 0,a = 0,b = 0,c = 0,ans = 0;
    TreeNode* root1;
    void dfs(TreeNode* root,TreeNode* root1){
        if(root->left == nullptr && root->right == nullptr){
            root1->val = (root->val ==0?1:0);
        }
        if(!root) return;

        cnt ++;
        root1 = new TreeNode(0);
        dfs(root->left,root1->left);

        dfs(root->right,root1->right);


        root1->val = (root->left == nullptr?0:root1->left->val)+(root->right == nullptr?0:root1->right->val) + (root->val==0?1:0);
    }
    void dfs2(TreeNode* root,TreeNode* root1){
        if(!root) return;
        ans ++;
        a = -(root->val == 0?1:0) + root1->val;
        b = -(root->left->val == 0?1:0) - (root->right->val == 0?1:0) + root1->val;
        c = cnt - root1->val;
        dfs(root->left,root1->left);
        dfs(root->right,root1->right);

    }
    int closeLampInTree(TreeNode* root) {
        dfs(root,root1);
        dfs2(root,root1);
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}