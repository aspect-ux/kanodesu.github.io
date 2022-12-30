#include <iostream>
#include <bits/stdc++.h>
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<int> ans;
        qu.push(root);
        while (!qu.empty()) {
            int maxv = INT32_MIN;
            for (int i = 0; i < qu.size(); i ++) {
                TreeNode* e = qu.front();
                qu.pop();
                if (maxv < e->val) maxv = e->val;
                if (e->left) qu.push(e->left);
                if (e->right) qu.push(e->left);
            }
            ans.push_back(maxv);
        }
        return ans;
    }
};