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
    unordered_map<int,int> index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //通过先序和中序定位根节点；大体思路为：找根节点，找左子节点，找右子节点，递归；
        //先将根节点保存在hash表中便于查询
        for(int i = 0; i < preorder.size();i ++){
            index[inorder[i]] = i;
        }
        int n = preorder.size();
        return mybuildTree(preorder,inorder,0,n-1,0,n-1);

    }
    TreeNode* mybuildTree(vector<int>& preorder, vector<int>& inorder,int pre_l,int pre_r,int in_l,int in_r){
        if(pre_r > in_l) return nullptr;
        int pre_root = pre_l;             //得到先序根节点在先序中的下标
        int in_root = index[preorder[0]]; //得到中序根节点在中序的下标
        TreeNode* root = new TreeNode(preorder[pre_root]);//  in_root - in_l 是左子树的个数，用中序来算个数
        root->left = mybuildTree(preorder,inorder,pre_l+1,pre_l + in_root - in_l,in_l,in_root - 1);
        // 改变先序区间，中序区间，其中先序区间左加一，而右则是到底;中序左不变，但右减一，因为去除了root
        //同理可得到右子树
        root->right = mybuildTree(preorder,inorder,pre_l +in_root - in_l + 1,pre_r,in_root + 1,in_r);
        return root;
  
    }
};
int main(){

    system("pause:");
    return 0 ;
}