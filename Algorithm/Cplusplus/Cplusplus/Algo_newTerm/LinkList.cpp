#include<iostream>
using namespace std;
/*
实验1.逆置单链表
对于不带头结点的单链表L,设计一个递归算法逆置所有结点。编写完整的实验程
并采用相应数据进行测试。
实验2。判断两棵二叉树是否同构
假设二叉树采用二叉链存储结构存放，设计一个递归算法判断两棵二叉树b1和b2
是否同构。编写完整的实验程序，并采用相应数据进行测试。

*/
struct ListNode{
	ListNode* next;
	int val;
	ListNode(int x):val(x),next(NULL){
	}
};
void LinkListReverse(ListNode* p,ListNode* q){
	if(p == q || q->next == p) return;
	ListNode* s = p;
	swap(p->val,q->val);
	while(s->next != q){
		s = s->next;
	}
	q = s;
	LinkListReverse(p->next,q); 
}
ListNode* insertNode(ListNode* &head, int data){
	ListNode* newNode = new ListNode(data);
	ListNode* p = head;
	if (p == NULL){
		head = newNode;
	}
	else{
		while (p->next != NULL){
			p = p->next;
		}
		p->next = newNode;
	}
    
	return head;
}


int main(){
	//----------REVERSE-----------
	//插入数据  不带头节点 
	int a[] = {1,2,3,4,5,6};
	ListNode* head = NULL;
	for(int i = 0; i < 6; i ++){
        
		insertNode(head,a[i]);
        cout<<a[i];
	} 
	ListNode* p = head;
	cout<<endl;
	
	//递归逆置
	ListNode* p1 = head,*q = p;
	while(p->next != NULL){
		p = p->next;
	}
	LinkListReverse(q,p);
	
	//输出结果
	p = head;
	for(int i = 0; i < 6; i ++){
		cout<<p->val;
		p = p->next; 
	} 
	
	//----------REVERSE-----------
	system("pause:");
	return 0;
} 