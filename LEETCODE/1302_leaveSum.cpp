#include<iostream>
#include<unordered_map>
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
    int sum = 0,ans = 0;
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            sum = 0;
            int n = qu.size();
            for(int i = 0;i < n; i++){
                TreeNode* tmp = qu.front();
                sum += tmp->val;
                if(tmp->left) {
                    sum += tmp->left->val;
                    qu.push(tmp->left);
                }
                if(tmp->right) {
                    sum += tmp->right->val;
                    qu.push(tmp->right);
                }
                qu.pop();
            }    
        }
        return sum;
    }
};
int main(){

    system("pause:");
    return 0;
}