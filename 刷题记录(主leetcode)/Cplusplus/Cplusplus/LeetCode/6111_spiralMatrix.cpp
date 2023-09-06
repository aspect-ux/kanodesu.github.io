#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int status = 0;
    int indiv(int a,int b,int m,int n){
        return a>=0&&a<m && b>=0&&b<n;
    }
    void dfs(int x,int y,ListNode* head,vector<vector<int>>& div,int m,int n,vector<vector<int>>& ans){
        if(!head) return;
        div[x][y] = 1;
        ans[x][y] = head->val;
       
        //右
        int tx = x,ty = y + 1;
        //运动不合法
        if(status == 0)
        if(!(indiv(tx,ty,m,n) && !div[tx][ty])){
             status = (status+1)%4;
        }//合法
        else if(status == 0){
            head = head->next;
           return dfs(tx,ty,head,div,m,n,ans);
        }
       
        //下
        tx = x + 1,ty = y;
        if(status == 1)
        if(!(indiv(tx,ty,m,n) && !div[tx][ty])){
             status = (status+1)%4;
        }
        else if(status == 1 ){
             head = head->next;
             return dfs(tx,ty,head,div,m,n,ans);
        }
        //左
        tx = x,ty = y - 1;
        if(status == 2)
        if(!(indiv(tx,ty,m,n) && !div[tx][ty])){
             status = (status+1)%4;
        }
        else if(status == 2){
            head = head->next;
           return dfs(tx,ty,head,div,m,n,ans);
        }
        //上
        tx = x - 1,ty = y;
        if(status == 3)
        if(!(indiv(tx,ty,m,n) && !div[tx][ty])){
             status = (status+1)%4;
        }
        else if(status == 3){
             head = head->next;
            return dfs(tx,ty,head,div,m,n,ans);
        }
        if(status == 0 && head->next)
        //重新开始转圈
        return dfs(x,y,head,div,m,n,ans);
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> div(m,vector<int>(n,0)),ans(m,vector<int>(n,-1));
        dfs(0,0,head,div,m,n,ans);
        return ans;
    }
};

int main(){
   
    system("pause:");
    return 0;
}