#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cstring>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class Solution {
public:
    unordered_map<int,int> hash;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        dfs(root->right);
        root->val = (root->left?root->left->val:0) + (root->right?root->right->val:0) + root->val;
        hash[root->val]++;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        int maxv = 0,i = 0;
        vector<int> ans;
        for(auto c : hash){
            if(c.second > maxv){
                maxv = c.second;
            }
        }
        for(auto c : hash){
            if(c.second == maxv){
                ans.push_back(c.first);
            }
        }
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}