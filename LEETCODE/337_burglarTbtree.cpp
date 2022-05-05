#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//wrong
/*
class Solution {
public:
    int rob(TreeNode* root) {
        int odd = 0,even = 0,flag = 0;
        queue<TreeNode*> qu,q;
        qu.push(root); 
        q = qu;
        while(!qu.empty()){
            root = qu.front();
            flag++;
            for(int i = 0;i < 2; i++){
                switch(i){
                    case 0:
                    if(root->left){
                        qu.push(root->left);
                        q.push(root->left);
                    }
                    break;
                    case 1:
                    if(root->right){
                        qu.push(root->right);
                        q.right(root->right);
                    }
                }
            } 
            qu.pop();
        }
        for(int i = 0; i )
        return max(odd,even);

    }
};*/
class Solution {
public:
    unordered_map<TreeNode*,int> f,g;
    int rob(TreeNode* root){
         if(!root) return;
         f[root] = root->val;
         g[root] = max(root->left->left->val + g[root],)
    }
};
int main(){
    queue<int> a;
    a.push(1);
    cout<<a.front()<<a.back()<<endl;

    system("pause:");
    return 0;
}