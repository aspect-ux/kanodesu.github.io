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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode *pre = head,*p = head;
        int cnt = k;
        while(cnt != 1){
            p = p->next;
            cnt --;
            if(!p) return head;
        }
        ListNode *m = p->next,*t;
        while(pre != p && p->next != pre){
            swap(pre->val,p->val);
            pre = pre->next;
            t = pre;
            while(t->next!=p){
                t = t->next;
            }
            p = t;
        }
        reverseKGroup(m,k);
        return head;
    }
};
int main(){
   
    system("pause:");
    return 0;
}