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
// 右视图，根据层序遍历，这一层但凡存在，就可以看到，这一层最后一个不为空
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> qu;
        int n = 0,data;
        qu.push(root);
        vector<int> ans;
        while(!qu.empty()){
            TreeNode* tmp = qu.front();
            n = qu.size();
            qu.pop();
            for(int i = 0; i < n; i ++){
                if(tmp) data = tmp->val;
                qu.push(tmp->left);
                qu.push(tmp->right);
            }
            ans.push_back(data);
        }
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}