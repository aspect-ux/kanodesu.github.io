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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* L = new ListNode(),*index = head->next,*q,* pre = L;//手动增加空结点
        L->next = head; 
        pre->next->next = nullptr;
        while(index){
            q = index->next;  //q用来存储
            while(pre->next && index->val >= pre->next->val){ //大于等于就往后移
                pre = pre->next;
            }
            index->next = pre->next; //插入
            pre->next = index;
            pre = L;          //重置
            index = q;
        }
        return L->next;
    }
};

int main(){
   
    system("pause:");
    return 0;
}