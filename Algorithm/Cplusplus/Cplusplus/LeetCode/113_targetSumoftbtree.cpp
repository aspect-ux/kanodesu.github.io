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
    void dfs(TreeNode* root,int targetSum,vector<int>& ans,vector<vector<int>>& res){
        if(!root) return;
        ans.push_back(root->val);
        if(!root->left&&!root->right){
           
            int sum = 0;
            for(int i = 0;i < ans.size(); i++){
                sum += ans[i];
            }
             cout<<root->val<<' '<<sum<<endl;
            if(sum == targetSum) res.push_back(ans);
            ans.pop_back();
            return;
        }
        dfs(root->left,targetSum,ans,res);
        dfs(root->right,targetSum,ans,res);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum){
        vector<vector<int>> res;
        vector<int> ans;
        dfs(root,targetSum,ans,res);
        return res;
    }
};
int main(){
    system("pause:");
    return 0;
}