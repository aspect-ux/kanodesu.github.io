#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};  //over https://leetcode-cn.com/problems/merge-k-sorted-lists/submissions/
//这里的链表的是不带头结点的
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * L,*p,*pre,*q;  //插入排序  ,虚拟一个头结点返回时再删
        vector<ListNode*>list1;
        int flag = 0;  //判断是否存在非空链表 
        L = new ListNode();   //判断是否存在不然没法设第一个数
        for(int i = 0; i < lists.size(); i++){
           if(lists[i]) {
                flag = 1;
               list1.push_back(lists[i]);
               
           }
       }
        if(!flag || lists.empty()) return NULL;
        p = new ListNode(list1[0]->val); 
        p->next = L->next;  //放第一个数
        L->next = p; 
      
        p =list1[0]->next;      
    for(int i = 0; i <list1.size(); i++){
       while(p){
            q = p->next;   //保存后续结点
             pre = L;     //插入操作关键找前驱 
            while(pre->next && pre->next->val < p->val ){
                pre = pre->next;
            }
            p->next = pre->next;    //将目标结点插入
            pre->next = p;

            p = q;        //p往后移
       }
       if(i ==list1.size() - 1) break;
       p =list1[i+1];    //一层结束前往下一个链表 

    }
    //别忘了把虚拟的头结点删除
    return L->next;
    }
};
int main(){


    system("pause:");
    return 0;
}