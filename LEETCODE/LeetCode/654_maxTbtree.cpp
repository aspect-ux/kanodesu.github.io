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
    TreeNode* dfs(vector<int>& nums,int l,int r){
        TreeNode* root;
        int maxIndex = l;
        if(l > r) return NULL;
        for(int i = l;i <= r; i++){
        if(nums[i] > nums[maxIndex])
        maxIndex = i;
        }
        root = new TreeNode();
        root->val = nums[maxIndex];
        cout<<root->val<<endl;
        root->left = dfs(nums,l,maxIndex - 1);
        root->right = dfs(nums,maxIndex + 1,r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums,0,nums.size() - 1);
    }
};
int main(){
    Solution s;
    vector<int> nums={3,2,1,6,0,5};
    TreeNode* a = s.constructMaximumBinaryTree(nums);

    system("pause:");
    return 0;
}