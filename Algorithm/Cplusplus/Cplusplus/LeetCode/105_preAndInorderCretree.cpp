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
/*
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
};*/
class Solution {
public:
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,int pre,int in,int n){
      //基本思路是递归
      //两个指针，pre，in
      //一个搜索指针p
      //当前子树的节点个数
      TreeNode* b;
      int p;
      if(n<=0) return NULL;
      b = new TreeNode();
      b->val = preorder[pre];
      for(p = in;p<in+n;p++){
          if(preorder[pre] == inorder[p])
          break;
      }
      int k = p - in;  //中序中的根节点下标
      b->left  = dfs(preorder,inorder,pre + 1,in,k);
      b->right = dfs(preorder,inorder,pre + k + 1,p + 1,n - k -1);
      //pre之所以为pre+k+1,因为先序是只需要顺序遍历就可以，但那是对于某一子树，现在是右子树，pre + 1 +k,
      //便于处理完左子树后跳转
      //n 更新为n - k -1
      return b;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder,inorder,0,0,preorder.size());
    }
};
int main(){

    system("pause:");
    return 0 ;
}