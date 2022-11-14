#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> ans;
        int depth = 0;
        qu.push(root);
        while(!qu.empty())
        {
            ans.push_back(vector<int>());
            int n = qu.size();
            for (int i = 0; i < n; i ++){
                TreeNode* tmp = qu.front();
                qu.pop();
                if(depth % 2 == 0){
                    ans[depth].push_back(tmp->val);
                }else{
                    ans[depth].insert(ans[depth].begin(),tmp->val);
                }
                if(tmp->left) qu.push(tmp->left);
                if(tmp->right) qu.push(tmp->right);
            }
            depth ++;
        }
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}