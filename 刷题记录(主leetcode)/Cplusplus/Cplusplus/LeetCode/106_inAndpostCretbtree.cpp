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
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder,int post,int in,int n){
        int p;
        TreeNode* b;
        if(n<=0) return NULL;
        b = new TreeNode();
        int r = post + n - 1;
        b->val = postorder[r]; //后序采取反过来的赋值，但还是采用先序构造
        for(p = in;p<in+n;p++){
            if(postorder[r] == inorder[p])
            break;
        }
        int k = p - in;
        b->left = dfs(inorder,postorder,post,in,k);
        b->right = dfs(inorder,postorder,post + k,p + 1,n - k - 1);
        return b;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder,postorder,0,0,inorder.size());
    }
};
int main(){

    system("pause:");
    return 0;
}