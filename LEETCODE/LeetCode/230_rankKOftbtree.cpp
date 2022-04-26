#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
二叉搜索树具有如下性质：

结点的左子树只包含小于当前结点的数。

结点的右子树只包含大于当前结点的数。

所有左子树和右子树自身必须也是二叉搜索树。
*/
//采取中序遍历
/*
class Solution {
public:
    void dfs(vector<int>&dp,TreeNode* root){
        if(!root) return;
        dp.push_back(root->val);
        dfs(dp,root->left);
        dfs(dp,root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> dp;
        dfs(dp,root);
         sort(dp.begin(),dp.end());
        for(int i = 0;i < dp.size(); i++){
            cout<<dp[i]<<endl;
        }
        return dp[k-1];
    }
};*/
//如何优化掉数组
class Solution {
public:
    void dfs(TreeNode* root,int &k,int& ans){
        if(!root) return;
        dfs(root->left,k,ans); //递归到达最小处
        if(0 == k)
        ans = root->val;
        k --;
        dfs(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
         dfs(root,k,ans);
        return ans;

    }
};
//中序遍历是从左到root到右
int main(){
    Solution s;
    s.kthSmallest(new TreeNode(),1);

    system("pause:");
    return 0;
}