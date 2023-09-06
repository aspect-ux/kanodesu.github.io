#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXSIZE 10

// ===============线性表=====================
// 基本操作：查询，插入，删除，合并 
// 存储方式：顺序存储（数组，地址连续），链式存储 
// ===============线性表=====================


// ===============START 链式存储：单链表=====================
// 为了方便，头结点不含数据 ，数据类型为int 
// Definition of single-linked list
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0),next(nullptr){} 	
};
static ListNode* L = new ListNode();

// 单链表类 
class SingleLinkList
{
public:
// Basic Operations
void InitSingleLinkList(){
}

// 插入：头插法 
void CreateFromHead(int n){
	L->next = nullptr;
	for (int i = 0; i < n; i ++)
	{
		ListNode* tmp = new ListNode();
		cin>>tmp->val;
		tmp->next = L->next;
		L->next = tmp;
	}
}
// 插入：尾插法 
void CreateFromTail(int n){
	L->next = nullptr;
	ListNode* tail = L;
	
	for (int i = 0; i < n; i ++)
	{
		ListNode* tmp = new ListNode();
		cin>>tmp->val;
		tmp->next = tail->next;
		tail->next = tmp;
		
		tail = tail->next;
	}
	
	// 最后tail指向最后一个结点 
}
// 查询：根据下标获取结点 ,注意，由于第一个结点不含数据，所以index为第n个结点 index>=1&&index<=n
// TODO: 可根据需求更改 
ListNode* GetAt(int index){
	ListNode* res = L;
	for (int i = 0; i < index; i ++)
	{
		res = res->next;
	}
	
	if (res == nullptr)
		cout<<"查找失败"<<endl; 
	
	return res;
}
// 查询：根据值获取结点 
// TODO: 获取第一个符合要求的值，可根据需求拓展更改 
ListNode* Get(int value){
	ListNode* res = L->next;
	while (res != nullptr)
	{
		if (res->val == value)
			return res;
		res = res->next;
	}
	
	cout<<"查找失败"<<endl; 
	return res;
}

// 获取单链表长度 
int GetLength(int value){
	int length = 0;
	ListNode* res = L->next;
	while (res != nullptr)
	{
		length ++;
		res = res->next;
	}
	
	return length;
}
// 删除: 删除第index个结点 ，也可以拓展删除值为value的结点 
void DeleteLinkList(int index){
	// 删除second所指 
	ListNode *second = L->next,*first = L;
	for (int i = 0; i < index; i ++)
	{
		second = second->next;
		if (second == nullptr) {
			printf("不存在第%d个结点",index); 
			return;
		}
		
		first = first->next;
	}
	first->next = second->next;
	delete second;
}

// 删除：清空单链表 
void ClearLinkList(){
	while (L->next)
	{
		ListNode *start = L->next;
		
		// 删除最后一个结点 
		while (start->next != nullptr)
		{
			start = start->next;
		}
		delete start;
	}
}
// 合并两个单链表 
// 1. 有序单链表的合并，已知LA,LB有序（非递减），合并后得到LC依旧有序 
ListNode* Merge(ListNode* LA,ListNode* LB){
	ListNode *LC = new ListNode(), *pa = LA->next,*pb = LB->next, *pc = LC;
	
	while(pa!= nullptr && pb!= nullptr)
	{
		if (pa->val < pb->val)
		{
			pc->next = pa;
			pc = pc->next;
			
			pa = pa->next;
		}
		else 
		{
			pc->next = pb;
			pc = pc->next;
			
			pb = pb->next;
		}
	}
	
	// pa不为空，全部放到LC后面 否则将pb放入 
	if (pa) pc->next = pa;
	else pc->next = pb;
	
	return LC; 
}

void PrintLinkList()
{
	ListNode* p = L->next;
	int count = 0;
	
	printf("=====start to print link list L:\n");
	while (p)
	{
		count ++;
		printf("第%d个结点的value: %d\n",count,p->val);
		p = p->next;
	}
	printf("======end======\n");
} 
};

SingleLinkList test_Linklist;

// NOTE TIME:
// 1. C++中NULL本质上是0，C中NULL则是空指针 。因为C++中空指针无法转换成其他指针，使用nullptr替代。 

// ===============END 链式存储：单链表=====================



// 循环链表： 首尾相接的单链表（省略） 

// ===============START 链式存储：双向链表=====================
// Definition of double-linked list
struct DoubleListNode
{
	int val;
	DoubleListNode *next,*prior;
	DoubleListNode() : val(0),next(nullptr),prior(nullptr){} 	
};

static DoubleListNode * DL; 
// 循环链表类
class DoubleLinkList
{
public:
	// 双向链表的前插 
	// 插入：头插法 
void CreateFromHead(int n){
	DL->next = nullptr;
	for (int i = 0; i < n; i ++)
	{
		DoubleListNode* tmp = new DoubleListNode();
		cin>>tmp->val;
		
		if (i == 0) 
		{
			tmp->next = DL;
			DL->prior = tmp;
			continue;
		}
		
		tmp->next = DL->next;
		tmp->prior = DL;
		
		DL->next = tmp;
	}
}
		
};
// ===============END 链式存储：双向链表=====================


// 静态链表：用数组

// TODO: 多项式的表示 

int main()
{
	// 1. 测试单链表
	// - 创建单链表 ,头插倒排 
	test_Linklist.CreateFromHead(MAXSIZE);  
	test_Linklist.PrintLinkList();
	return 0;
} 
