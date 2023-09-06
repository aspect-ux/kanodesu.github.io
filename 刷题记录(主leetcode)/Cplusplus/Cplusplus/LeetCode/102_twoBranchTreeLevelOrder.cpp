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
/*1
class Solution {
public:
    void func(int n,TreeNode* p,vector<vector<int>> & ans){ 
        if(!p) return;
        if(n >= ans.size())
        ans.push_back(vector<int>{});//由于每次递归调用会需要新增一行，但是对于动态vector不能直接用下标访问
        //于是每次递归调用前，新增一个vector<int>{}
        ans[n].push_back(p->val);
        func(n + 1,p->left,ans);
        func(n + 1,p->right,ans);
        
    }
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> ans;
        func(0,root,ans);
        return ans;
    }
};*/
class Solution {
public:   //层序遍历  队列非递归
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> qu;
    qu.push(root);
    while(!qu.empty()){
        int len = qu.size();
         vector<int> ans;
        for(int i = 0 ;i < len; i++){
            TreeNode* e = qu.front();
            qu.pop();
            if(e->left){
                qu.push(e->left);  
            }
            if(e->right){
                qu.push(e->right);
            }
            ans.push_back(e->val);
        }
        res.push_back(ans);
    }
    return res;
    }
};
int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    vector<vector<int>> a = s.levelOrder(root);
    for(int i = 0;i < a.size(); i++){
        for(int j = 0;j < a[0].size(); j++){
            cout<<a[i][j]<<endl;
        }
    }


    system("pause:");
    return 0;
}