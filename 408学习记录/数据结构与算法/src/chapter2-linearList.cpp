#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXSIZE 10

// ===============���Ա�=====================
// ������������ѯ�����룬ɾ�����ϲ� 
// �洢��ʽ��˳��洢�����飬��ַ����������ʽ�洢 
// ===============���Ա�=====================


// ===============START ��ʽ�洢��������=====================
// Ϊ�˷��㣬ͷ��㲻������ ����������Ϊint 
// Definition of single-linked list
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0),next(nullptr){} 	
};
static ListNode* L = new ListNode();

// �������� 
class SingleLinkList
{
public:
// Basic Operations
void InitSingleLinkList(){
}

// ���룺ͷ�巨 
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
// ���룺β�巨 
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
	
	// ���tailָ�����һ����� 
}
// ��ѯ�������±��ȡ��� ,ע�⣬���ڵ�һ����㲻�����ݣ�����indexΪ��n����� index>=1&&index<=n
// TODO: �ɸ���������� 
ListNode* GetAt(int index){
	ListNode* res = L;
	for (int i = 0; i < index; i ++)
	{
		res = res->next;
	}
	
	if (res == nullptr)
		cout<<"����ʧ��"<<endl; 
	
	return res;
}
// ��ѯ������ֵ��ȡ��� 
// TODO: ��ȡ��һ������Ҫ���ֵ���ɸ���������չ���� 
ListNode* Get(int value){
	ListNode* res = L->next;
	while (res != nullptr)
	{
		if (res->val == value)
			return res;
		res = res->next;
	}
	
	cout<<"����ʧ��"<<endl; 
	return res;
}

// ��ȡ�������� 
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
// ɾ��: ɾ����index����� ��Ҳ������չɾ��ֵΪvalue�Ľ�� 
void DeleteLinkList(int index){
	// ɾ��second��ָ 
	ListNode *second = L->next,*first = L;
	for (int i = 0; i < index; i ++)
	{
		second = second->next;
		if (second == nullptr) {
			printf("�����ڵ�%d�����",index); 
			return;
		}
		
		first = first->next;
	}
	first->next = second->next;
	delete second;
}

// ɾ������յ����� 
void ClearLinkList(){
	while (L->next)
	{
		ListNode *start = L->next;
		
		// ɾ�����һ����� 
		while (start->next != nullptr)
		{
			start = start->next;
		}
		delete start;
	}
}
// �ϲ����������� 
// 1. ��������ĺϲ�����֪LA,LB���򣨷ǵݼ������ϲ���õ�LC�������� 
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
	
	// pa��Ϊ�գ�ȫ���ŵ�LC���� ����pb���� 
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
		printf("��%d������value: %d\n",count,p->val);
		p = p->next;
	}
	printf("======end======\n");
} 
};

SingleLinkList test_Linklist;

// NOTE TIME:
// 1. C++��NULL��������0��C��NULL���ǿ�ָ�� ����ΪC++�п�ָ���޷�ת��������ָ�룬ʹ��nullptr����� 

// ===============END ��ʽ�洢��������=====================



// ѭ������ ��β��ӵĵ�����ʡ�ԣ� 

// ===============START ��ʽ�洢��˫������=====================
// Definition of double-linked list
struct DoubleListNode
{
	int val;
	DoubleListNode *next,*prior;
	DoubleListNode() : val(0),next(nullptr),prior(nullptr){} 	
};

static DoubleListNode * DL; 
// ѭ��������
class DoubleLinkList
{
public:
	// ˫�������ǰ�� 
	// ���룺ͷ�巨 
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
// ===============END ��ʽ�洢��˫������=====================


// ��̬����������

// TODO: ����ʽ�ı�ʾ 

int main()
{
	// 1. ���Ե�����
	// - ���������� ,ͷ�嵹�� 
	test_Linklist.CreateFromHead(MAXSIZE);  
	test_Linklist.PrintLinkList();
	return 0;
} 
