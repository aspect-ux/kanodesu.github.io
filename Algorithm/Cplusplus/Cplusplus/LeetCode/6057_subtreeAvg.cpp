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
// 该题主要是同时记录个数和sum
// 1.要么暴力法，两个递归，一个用来dp，一个用来判断
// 2.要么一个递归，返回pair类型，这样每次就能达到同时dp

//1
/*
class Solution {
public:
    int sum = 0, num = 0,ans = 0;
    void dfs(TreeNode* root){
        if(!root) return;
        sum = 0;
        num = 0;
        visit(root);
        if(sum / num == root->val) ans++;
        dfs(root->left);
        dfs(root->right);
    }
    //计算sum和root
    void visit(TreeNode* root){
        if(!root) return;
        sum += root->val;
        num ++;
        visit(root->left);
        visit(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};*/
class Solution {
public:
    int ans = 0;
    pair<int,int> dfs(TreeNode* root){
        if(!root) return pair(0,0);
        pair<int,int> l = dfs(root->left),r = dfs(root->right);
        int sum = l.first + r.first + root->val;
        int num = l.second + r.second + 1;
        if(sum / num == root->val)
        ans ++;
        return pair(sum,num);
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
int main(){
    Solution s;
    TreeNode* root;
    root=new TreeNode();
    root->val = 4;
    root->left = new TreeNode();
    root->left->val = 8;
     root->right = new TreeNode();
    root->right->val = 5;
     root->left->left = new TreeNode();
    root->left->left->val = 0;
    root->left->right = new TreeNode();
    root->left->right->val = 1;
    root->right->left = new TreeNode();
    root->right->left = nullptr;
     root->right->right = new TreeNode();
    root->right->right->val = 6;
    cout<<s.averageOfSubtree(root);
    system("pause:");
    return 0;
}