#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//注意此间题无头结点
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list3,*head,*q,*t;
        list3 = new ListNode();   //作头节点
        head = list3;
        while(list1&&list2){
            if(list1->val<list2->val){
                q = list1->next;
                list1->next = list3->next;
                list3->next = list1;  //小的那个传，把list1插入到list3后面
                list3 = list3->next;  //充当pre的角色
                list1 = q;
            }
            else{
                t = list2->next;
                list2->next = list3->next;
                list3->next = list2;
                 list3 = list3->next;
                 list2 = t;
            }
        }
        if(!list1){                   //如果list1先到头，就把list2原封传给list3
            while(list2){
                t = list2->next;
                list2->next = list3->next;
                list3->next = list2;
                 list3 = list3->next;
                 list2 = t;
                
            }
        }
        else{
            while(list1){
               q = list1->next;
                list1->next = list3->next;
                list3->next = list1;  //小的那个传，把list1插入到list3后面
                list3 = list3->next;  //充当pre的角色
                list1 = q;
        }
        
        }
        return head->next;
        
    }

};
int main(){



    system("pause:");
    return 0;
}