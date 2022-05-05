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
    TreeNode* removeLeafNodes(TreeNode* root, int target){
        if(!root) return NULL;
        root->left = removeLeafNodes(root->left,target);
        root->right = removeLeafNodes(root->right,target);
        if(!root->left && !root->right && root->val == target){
            return NULL;
        }
        return root;
    }
};
int main(){
    Solution s;
    vector<int> nums={3,2,1,6,0,5};
    system("pause:");
    return 0;
}