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
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> qu;
        int ans = 0,depth = 0,res = 0;
        qu.push(root);
        while(!qu.empty())
        {
            int n = qu.size(),sum = 0;
            depth ++;
            for (int i = 0; i < n; i ++)
            {
                TreeNode* tmp = qu.front();
                qu.pop();
                if(tmp->left) qu.push(tmp->left);
                if(tmp->right) qu.push(tmp->right);
                sum += tmp->val;
            }
            if(sum > ans)
            {
                res = depth;
                ans = sum;
            }
        }
        return res;
    }
};
int main(){
    
    system("pause:");
    return 0;
}