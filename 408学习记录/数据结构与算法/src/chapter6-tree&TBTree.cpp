#include <stdio.h> 
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#include <memory>
#include <algorithm>
using namespace std;

//==============���������=================
//����ʲô��n(n>=0)���������޼���T
//   - ÿ������ж������һ��ǰ�������ҽ���һ��root
//   - ��ʾ������һ�������α�ʾ�����������ϱ�ʾ���ȼ�P46
//   - �ȣ���������
//   - �㣺root��һ�㣬max���Ϊ�߶� 


///<summery>
/// ���¾�Ϊ������ 
///</summery>
 
struct TreeNode {
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : key(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : key(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : key(x), left(left), right(right) {}
};
static TreeNode *root;

// ==================ǰ��====================== 
// TODO: ʹ�õ���c++ stl����������д
// ����ע�ͽ�ϵ������ṹ 
// ==================ǰ��====================== 

// START ������
class TBTree
{
public:
	//================START TBTree Basic Operations===============
	void Init(){
		
	}
	
	// ʹ��ǰ��������������� 
	virtual void Create(TreeNode *res){
		if (stopInput) return;
		
		// ���뻻�� TODO:���⣺����̫�� 
		string keyue;
		cin>>keyue;
		if (keyue == "end") {
			cout<<1<<endl;
			stopInput = true;
			return;
		}

		if (keyue == "null") return;
		
		res = new TreeNode();
		// ��֧��int���ͣ���������� 
		res->key = stoi(keyue);
		
		Create(res->left);
		Create(res->right);
	}
	void Destory();
	bool Empty(){
		return !root;
	}
	void Root();
	void Parent();
	void LeftChild();
	void RightChild();
	
	void Clear();
	
	// ������ 
	void PrintTBTreeNode(TreeNode *node)
	{
		printf("%d ",node->key);
	}
	//================END TBTree Basic Operations===============
	
	//================START �ݹ�ʵ�ֱ���==================== 
	// �������ı��� 
	void Traverse();
	
	/// dfs
	// - ǰ����� 
	void PreOrderTraverse(TreeNode *root)
	{
		if (!root)
			return;
		// TODO:�Ե�ǰ������ 
		PrintTBTreeNode(root);
		PreOrderTraverse(root->left);
		PreOrderTraverse(root->right);
	}
	// - ������� 
	void InOrderTraverse(TreeNode *root){
		if (!root)
			return;
		InOrderTraverse(root->left);
		// TODO:�Ե�ǰ������ 
		PrintTBTreeNode(root);
		InOrderTraverse(root->right);
	}
	// - �������
	void PostOrderTraverse(TreeNode *root)
	{
		if (!root)
			return;
		PreOrderTraverse(root->left);
		PreOrderTraverse(root->right);
		// TODO:�Ե�ǰ������ 
		PrintTBTreeNode(root);
	}
	//================END �ݹ�ʵ�ֱ���==================== 
	
	// =================START: �����ķǵݹ��㷨=================================== 
	// ����˼·�������ǰ��㲻Ϊ�գ�ѭ�����+�ж����ӽ�㣻
	//				���Ϊ�գ���ζ����Ҫ���ݣ�pop�����һ����㣬��ȡtop�����������ظ����ϡ� 
	void PreOrderTraverse1(TreeNode *root)
	{
		stack<TreeNode*> st;
		TreeNode* node = root;
		while (node || !st.empty()) // nodeָ��ǰ��ָ�룬stack�洢�������ľ�ָ�� 
		{
			if (node)
			{
				// ����������������ǰ���(��),��֤push��ȥ�Ľ�㲻Ϊ��
				PrintTBTreeNode(node);
				st.push(node);
				node = node->left;
			}
			else
			{
				node = st.top()->right;
				st.pop();
			}
		}		
	}
	
	// ����: ���󣬺��У�����ң����������λ�ô�����ķǿ����ӽ�㿪ʼ�������ҵķǿ����ӽ������� 
	void InOrderTraverse1(TreeNode *root){
		if (!root) return;
		stack<TreeNode*> st;
		TreeNode* node = root;
		while (node || !st.empty())
		{
			if (node)
			{
				st.push(node);
				node = node->left;
			}
			else
			{
				// ���������� ����ķǿս��(�������)
				node = st.top();
				st.pop();
				// TODO: ���λ�� 
				PrintTBTreeNode(node); 
				
				// ת��ָ�뵽�ҽ��,��Ϊ������Ҳ��Ҫ�ݹ��ж� 
				node = node->right; 
			}
		}		
	}
	
	// ����-��Ҫ 
	void PostOrderTraverse1(TreeNode *root){
		if (!root) return;
		stack<TreeNode*> st;
		TreeNode* node = root,*recent = nullptr;
		while (node || !st.empty())
		{
			if (node)
			{
				st.push(node);
				node = node->left;
			}
			else
			{
				// ���������Ҫ������ҽ����������Ը����				
				node = st.top();				
				// ֱ�����ӽ���ǿս������ 
				if (node->right && node->right != recent)
				{
					st.push(node->right);
					node = node->right->left;
				}
				else
				{
					// TODO: ���λ�� 
					PrintTBTreeNode(node);
					recent = st.top();
					st.pop();
					node = nullptr;
				}
			}
		}		
	}
	// =================END: �����ķǵݹ��㷨===================================
	
	
	/// bfs
	// ������� 
	// �����õ�std::queue
	void LevelOrderTraverse(TreeNode *root)
	{ 
		if (!root) return;
		qu.push(root);
		level = 0;
		while(!qu.empty())
		{
			int n = qu.size();
			LevelArr.push_back(vector<int>());
			for (int i = 0; i < n; i ++)
			{
				TreeNode *tmp = qu.front();
				qu.pop();
				// TODO:�����������
				PrintTBTreeNode(tmp);
				LevelArr[level].push_back(tmp->key); //��ά�����¼ 
				if (tmp->left)
					qu.push(tmp->left);
				if (tmp->right)
					qu.push(tmp->right);
			}
			level ++; 
		}
	} 

	
	//===============START TBTree Application(�йض�������һЩӦ��)=================
	//1.���Ҷ�ӽ��: ʹ���������ֱ�������֮һ����TODO�������ж���� ���ԣ� 
	//2.���Ҷ�ӽڵ���Ŀ�� ͬ�� ���ԣ� 
	//3.��������߶� -3.1 max(leftH,rightH) + 1�ݹ�  -3.2 ǰ��������� 
	//  ����ʵ��һ��3.1�ķ��� 
	int GetHeight(TreeNode *root)
	{
		if (!root) return 0; 
		return max(GetHeight(root->left),GetHeight(root->right)) + 1;
	} 
	//4.(ѡ��������״��ӡ������  
	//===============END TBTree Application===================
	
	//===============START ��������������==================== 
	//===============END ��������������==================== 
private:
	queue<TreeNode*> qu;
	vector<vector<int>> LevelArr; // ��ά�洢ÿ����keyue 
	vector<TreeNode*> LeavesArr;
	
	bool stopInput = false;
	int level = 0;
};


// ��������� 
struct ThreadTreeNode {
    int key;
    int lTag; // 0��ʾ�洢�����ӽ��ָ�룬1��ʾ�洢���� 
    int rTag;
    ThreadTreeNode *left;
    ThreadTreeNode *right;
    ThreadTreeNode() : key(0), lTag(0), rTag(0), left(nullptr), right(nullptr) {}
    ThreadTreeNode(int x) : key(x), lTag(0), rTag(0),left(nullptr), right(nullptr) {}
    ThreadTreeNode(int x,int lTag,int rTag, ThreadTreeNode *left, ThreadTreeNode *right)
	: key(x),lTag(lTag), rTag(rTag), left(left), right(right) {}
};
static ThreadTreeNode* threadRoot;
// �������� 
class ThreadTree : public TBTree
{
	//================START ������==========================
	void Create(ThreadTreeNode *res){
		pre = res;
	}
	
	// ���������� 
	void InitThread(ThreadTreeNode* threadRoot)
	{
		if(!threadRoot) return;
		
		InitThread(threadRoot->left);
		
		// ������Ϊ�գ���ô�洢ǰ�� 
		if (!threadRoot->left)
		{
			threadRoot->left = pre; 
			threadRoot->lTag = 1; 
		}
		
		// ������Ϊ����ǰ����㲻Ϊ�գ��洢���� 
		if (!threadRoot->right && pre)
		{
			pre->right = threadRoot;
			pre->rTag = 1; 
		}
		
		// ��¼ǰ����� 
		pre = threadRoot;
		
		InitThread(threadRoot->right);
	}
private:
	ThreadTreeNode* pre = nullptr;
		

};
//================END ������============================

//================START ��������============================
#define N 10 //Ҷ�ӽ��
#define M 2*N - 1 // �ܽ���� 
typedef struct HuffmanNode
{
	int w; // Ȩ��
	int p; // ˫�׵��±�,Ϊ0ʱ��ʾ��û�и����,�ɹ��졣 
	int left; // �󺢵��±�
	int right; // �Һ����±� 
}HuffmanTree[M+1]; 
HuffmanTree HT;

class Huffman
{
public:
	// ����
	void Select(HuffmanTree HT,int n, int &s1, int &s2)
	{
		int s1_keyue,s2_keyue = s1_keyue = INT_MAX;
		for (int i = 1; i <= n; i ++){
			if (s1_keyue > HT[i].w && HT[i].p == 0)
			{
				s1_keyue = HT[i].w;
				s1 = i;
			}
		}
		for (int i = 1; i <= n; i ++)
		{
			// ���ҵڶ�С��Ȩ�� �� ������ 
			if (HT[i].w != s1_keyue && HT[i].w < s2_keyue && HT[i].p == 0)
			{
				s2_keyue = HT[i].w;
				s2 = i;
			}
		}
	}
	void CreateHuffmanTree(int w[],int n,int m)
	{
		// HT[0]��ʹ�� 
		// ǰn�����洢Ҷ�� 
		for (int i = 1; i <= n; i ++)
		{
			HT[i] = {w[i],0,0,0};
		}
		
		// ��n-1�洢��Ҷ��
		for (int i = n+1; i <= m; i ++) HT[i] = {0,0,0,0};
		for (int i = n+1; i <= m; i ++)
		{
			int s1,s2;
			// ѡ����С������, 
			Select(HT,i-1,s1,s2);  // ÿ��ѡ�е�����Ҷ�Ӷ��޷���ʹ���� �����Ǹ���㻹���Լ���ѡ�� 
			HT[i].w = HT[s1].w + HT[s2].w;
			HT[s1].p = i; HT[s2].p = i; 
			HT[i].left = s1; HT[i].right = s2;
		}
	}
	
	//cd = (char*)malloc((n+1)sizeof(char));
	//cd[n-1] = ' \0'; // \0�����ַ����������ţ��κ��ַ�������
		
	
	// �����������㷨
	void HuffmanCode(int n)
	{
		// ����Ҷ�� 
		for (int i = 1; i <= n; i ++)
		{
			int p = HT[i].p; // ��ȡ��ǰҶ�ӽ��ĸ����
			string code = "";
			// ��Ҷ�ӽ�㿪ʼ���ϱ��� 
			while(p)
			{
				if (HT[p].left == p) code += '0';
				else code += '1';
				p = HT[p].p; 
			} 
			//reverse(code.begin(),code.end());
			ReverseString(code);
			huffmanCode.push_back(code);
		} 
	} 
	void ReverseString(string& code)
	{
		int n = code.size();
		for (int i = 0,j = n - 1; i < n/2; i ++, j --)
		{
			swap(code[i],code[j]);
		}
		
	}
private:
	vector<string> huffmanCode;
};


//================END ��������============================

int main()
{
	// ���������� 
	shared_ptr<TBTree> tbTree = make_shared<TBTree>();
	
	// Ĭ������nullΪ�� 
	int n = 3; // ���������� 
	tbTree->Create(root);
	tbTree->InOrderTraverse(root); 
	cout<<root->right->key; 
	
	
	// Huffman test
	Huffman hf;
	int w[N];
	hf.CreateHuffmanTree(w,N,M);
	
	return 0;
} 
