#include <stdio.h> 
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#include <memory>
#include <algorithm>
using namespace std;

//==============树与二叉树=================
//树是什么？n(n>=0)个结点的有限集合T
//   - 每个结点有多个后驱一个前驱，有且仅有一个root
//   - 表示方法：一般是树形表示法，还有文氏表示法等见P46
//   - 度：子树个数
//   - 层：root在一层，max层称为高度 


///<summery>
/// 以下均为二叉树 
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

// ==================前言====================== 
// TODO: 使用到了c++ stl，有需求重写
// 以下注释结合倒置树结构 
// ==================前言====================== 

// START 二叉树
class TBTree
{
public:
	//================START TBTree Basic Operations===============
	void Init(){
		
	}
	
	// 使用前序遍历创建二叉树 
	virtual void Create(TreeNode *res){
		if (stopInput) return;
		
		// 输入换行 TODO:问题：创建太慢 
		string keyue;
		cin>>keyue;
		if (keyue == "end") {
			cout<<1<<endl;
			stopInput = true;
			return;
		}

		if (keyue == "null") return;
		
		res = new TreeNode();
		// 仅支持int类型，按需求更改 
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
	
	// 输出结点 
	void PrintTBTreeNode(TreeNode *node)
	{
		printf("%d ",node->key);
	}
	//================END TBTree Basic Operations===============
	
	//================START 递归实现遍历==================== 
	// 二叉树的遍历 
	void Traverse();
	
	/// dfs
	// - 前序遍历 
	void PreOrderTraverse(TreeNode *root)
	{
		if (!root)
			return;
		// TODO:对当前结点操作 
		PrintTBTreeNode(root);
		PreOrderTraverse(root->left);
		PreOrderTraverse(root->right);
	}
	// - 中序遍历 
	void InOrderTraverse(TreeNode *root){
		if (!root)
			return;
		InOrderTraverse(root->left);
		// TODO:对当前结点操作 
		PrintTBTreeNode(root);
		InOrderTraverse(root->right);
	}
	// - 后序遍历
	void PostOrderTraverse(TreeNode *root)
	{
		if (!root)
			return;
		PreOrderTraverse(root->left);
		PreOrderTraverse(root->right);
		// TODO:对当前结点操作 
		PrintTBTreeNode(root);
	}
	//================END 递归实现遍历==================== 
	
	// =================START: 遍历的非递归算法=================================== 
	// 先序思路，如果当前结点不为空，循环输出+判断左子结点；
	//				如果为空，意味着需要回溯，pop出最后一个结点，获取top的右子树；重复以上。 
	void PreOrderTraverse1(TreeNode *root)
	{
		stack<TreeNode*> st;
		TreeNode* node = root;
		while (node || !st.empty()) // node指向当前新指针，stack存储待开发的旧指针 
		{
			if (node)
			{
				// 先序遍历：先输出当前结点(左),保证push进去的结点不为空
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
	
	// 中序: 先左，后中，最后右，遍历的输出位置从最左的非空左子结点开始，到最右的非空右子结点结束。 
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
				// 中序遍历输出 最左的非空结点(输出左结点)
				node = st.top();
				st.pop();
				// TODO: 输出位置 
				PrintTBTreeNode(node); 
				
				// 转移指针到右结点,因为右子树也需要递归判断 
				node = node->right; 
			}
		}		
	}
	
	// 后序-重要 
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
				// 后序遍历需要先输出右结点才能输出相对根结点				
				node = st.top();				
				// 直到右子结点是空结点才输出 
				if (node->right && node->right != recent)
				{
					st.push(node->right);
					node = node->right->left;
				}
				else
				{
					// TODO: 输出位置 
					PrintTBTreeNode(node);
					recent = st.top();
					st.pop();
					node = nullptr;
				}
			}
		}		
	}
	// =================END: 遍历的非递归算法===================================
	
	
	/// bfs
	// 层序遍历 
	// 这里用到std::queue
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
				// TODO:层序遍历操作
				PrintTBTreeNode(tmp);
				LevelArr[level].push_back(tmp->key); //二维数组记录 
				if (tmp->left)
					qu.push(tmp->left);
				if (tmp->right)
					qu.push(tmp->right);
			}
			level ++; 
		}
	} 

	
	//===============START TBTree Application(有关二叉树的一些应用)=================
	//1.输出叶子结点: 使用上述四种遍历方法之一，在TODO的区域判断输出 （略） 
	//2.输出叶子节点数目： 同上 （略） 
	//3.求二叉树高度 -3.1 max(leftH,rightH) + 1递归  -3.2 前序遍历计数 
	//  这里实现一下3.1的方法 
	int GetHeight(TreeNode *root)
	{
		if (!root) return 0; 
		return max(GetHeight(root->left),GetHeight(root->right)) + 1;
	} 
	//4.(选做）按树状打印二叉树  
	//===============END TBTree Application===================
	
	//===============START 其他二叉树操作==================== 
	//===============END 其他二叉树操作==================== 
private:
	queue<TreeNode*> qu;
	vector<vector<int>> LevelArr; // 二维存储每层结点keyue 
	vector<TreeNode*> LeavesArr;
	
	bool stopInput = false;
	int level = 0;
};


// 线索树结点 
struct ThreadTreeNode {
    int key;
    int lTag; // 0表示存储左右子结点指针，1表示存储线索 
    int rTag;
    ThreadTreeNode *left;
    ThreadTreeNode *right;
    ThreadTreeNode() : key(0), lTag(0), rTag(0), left(nullptr), right(nullptr) {}
    ThreadTreeNode(int x) : key(x), lTag(0), rTag(0),left(nullptr), right(nullptr) {}
    ThreadTreeNode(int x,int lTag,int rTag, ThreadTreeNode *left, ThreadTreeNode *right)
	: key(x),lTag(lTag), rTag(rTag), left(left), right(right) {}
};
static ThreadTreeNode* threadRoot;
// 线索树类 
class ThreadTree : public TBTree
{
	//================START 线索树==========================
	void Create(ThreadTreeNode *res){
		pre = res;
	}
	
	// 中序线索化 
	void InitThread(ThreadTreeNode* threadRoot)
	{
		if(!threadRoot) return;
		
		InitThread(threadRoot->left);
		
		// 左子树为空，那么存储前驱 
		if (!threadRoot->left)
		{
			threadRoot->left = pre; 
			threadRoot->lTag = 1; 
		}
		
		// 右子树为空且前驱结点不为空，存储后驱 
		if (!threadRoot->right && pre)
		{
			pre->right = threadRoot;
			pre->rTag = 1; 
		}
		
		// 记录前驱结点 
		pre = threadRoot;
		
		InitThread(threadRoot->right);
	}
private:
	ThreadTreeNode* pre = nullptr;
		

};
//================END 线索树============================

//================START 哈夫曼树============================
#define N 10 //叶子结点
#define M 2*N - 1 // 总结点数 
typedef struct HuffmanNode
{
	int w; // 权重
	int p; // 双亲的下标,为0时表示还没有父结点,可构造。 
	int left; // 左孩的下标
	int right; // 右孩的下标 
}HuffmanTree[M+1]; 
HuffmanTree HT;

class Huffman
{
public:
	// 构造
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
			// 查找第二小的权重 且 待构造 
			if (HT[i].w != s1_keyue && HT[i].w < s2_keyue && HT[i].p == 0)
			{
				s2_keyue = HT[i].w;
				s2 = i;
			}
		}
	}
	void CreateHuffmanTree(int w[],int n,int m)
	{
		// HT[0]不使用 
		// 前n个结点存储叶子 
		for (int i = 1; i <= n; i ++)
		{
			HT[i] = {w[i],0,0,0};
		}
		
		// 后n-1存储非叶子
		for (int i = n+1; i <= m; i ++) HT[i] = {0,0,0,0};
		for (int i = n+1; i <= m; i ++)
		{
			int s1,s2;
			// 选择最小的两个, 
			Select(HT,i-1,s1,s2);  // 每次选中的两个叶子都无法再使用了 ，但是父结点还可以加入选择 
			HT[i].w = HT[s1].w + HT[s2].w;
			HT[s1].p = i; HT[s2].p = i; 
			HT[i].left = s1; HT[i].right = s2;
		}
	}
	
	//cd = (char*)malloc((n+1)sizeof(char));
	//cd[n-1] = ' \0'; // \0代表字符串结束符号，任何字符串都有
		
	
	// 哈夫曼编码算法
	void HuffmanCode(int n)
	{
		// 遍历叶子 
		for (int i = 1; i <= n; i ++)
		{
			int p = HT[i].p; // 获取当前叶子结点的父结点
			string code = "";
			// 从叶子结点开始向上遍历 
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


//================END 哈夫曼树============================

int main()
{
	// 二叉树对象 
	shared_ptr<TBTree> tbTree = make_shared<TBTree>();
	
	// 默认输入null为空 
	int n = 3; // 二叉树层数 
	tbTree->Create(root);
	tbTree->InOrderTraverse(root); 
	cout<<root->right->key; 
	
	
	// Huffman test
	Huffman hf;
	int w[N];
	hf.CreateHuffmanTree(w,N,M);
	
	return 0;
} 
