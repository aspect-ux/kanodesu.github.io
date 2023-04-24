#include <iostream>
#include <vector>
#include <queue>
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> qu;
        root->val = 0;
        qu.push(root);
        while(!qu.empty())
        {
            int n = qu.size();
            long long sum = 0;
            vector<TreeNode*> tree;
            for (int i = 0; i < n; i ++)
            {
                TreeNode* e = qu.front();
                qu.pop();
                if (e->left)
                {
                    qu.push(e->left);
                    sum += e->left->val;
                    tree.push_back(e->left);
                }
                else if (e->right)
                {
                    qu.push(e->right);
                    sum += e->right->val;
                    tree.push_back(e->right);
                }
                if (!(e->right&&e->left) && (e->right || e->left))
                {
                    TreeNode* tmp = new TreeNode();
                    tmp->val = 0;
                    tree.push_back(tmp);
                }
            }
            n = tree.size()/2;
            cout<<n<<endl;
            for (int i = 0; i < n; i += 2)
            {
                tree[i]->val = tree[i+1]->val = sum - (tree[i]->val+tree[i+1]->val);
                cout<<tree[i]->val<<endl;
            }
        }
        return root;
    }
};