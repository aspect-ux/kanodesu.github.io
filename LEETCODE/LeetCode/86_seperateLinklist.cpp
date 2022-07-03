#include<iostream>
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *pre = head,*p = pre;
        while(1){
            while(p->val != x){
                p = p->next;
                if(!p) return head;
            }//到达x
            pre = p;
            p = p->next;
            



        }
        
    }
};
int main(){
    system("pause:");
    return 0;
}