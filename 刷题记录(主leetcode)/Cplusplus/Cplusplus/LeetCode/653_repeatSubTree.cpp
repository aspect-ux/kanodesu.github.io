#include<iostream>
#include<vector>
#include<unordered_map>
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
    vector<TreeNode*> ans;
    string s;
    unordered_map<string,int> hash;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        dfs(root->right);
        ans.push_back(root);
        s.push_back(root->val + '0');
        hash[s] ++;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        dfs(root);
        for(int i = 0; i < s.size(); i ++){
            for(int j = 1; j <= s.size(); j ++){
                hash[s.substr(i,j)] ++;
            }
        }
        for(auto c: hash){
            if(c.second > 1) res.push_back(c.first);
        }

        return res;
    }
};
int main(){
    
    system("pause:");
    return 0;
}