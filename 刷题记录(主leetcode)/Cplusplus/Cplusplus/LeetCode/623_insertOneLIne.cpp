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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> qu;
        int n = 0,d = 1;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* tmp = qu.front();
            n = qu.size();
            qu.pop();
            d ++;
            for(int i = 0; i < n; i ++){
                tmp = qu.front();
                qu.pop();
                if(depth == d){
                    if(!tmp) continue;
                    
                    TreeNode* p = new TreeNode(val,tmp->left,nullptr),*q = new TreeNode(val,tmp->right,nullptr);
                    tmp->left = p;
                    tmp->right = q;
                }else{
                    qu.push(tmp->left);
                    qu.push(tmp->right);
                }  
            }
            if(depth == d) break;
        }
        return root;
    }
};
int main(){
    
    system("pause:");
    return 0;
}