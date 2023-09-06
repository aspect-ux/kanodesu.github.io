#include<iostream>
#define type char
#define type char
#define MAX 20
using namespace::std;
struct treenode
{
	type data;
	int lchild;
	int rchild;
} tree1[MAX],tree2[MAX];
int buildtree(treenode tree[])
{
	bool book[MAX]= {false};
	int root;
	int N,i;
	char left,right;
	cin>>N;
	if(N)
	{
		for(i=0; i<N; i++)
		{
			cin>>tree[i].data>>left>>right;
			if(left!='-')
			{
				tree[i].lchild=left-'0';
				book[tree[i].lchild]=1;
			}
			else
				tree[i].lchild=-1;
			if(right!='-')
			{
				tree[i].rchild=right-'0';
				book[tree[i].rchild]=true;
			}
			else
				tree[i].rchild=-1;
		}
		for(i=0; i<N; i++)
			if(book[i])
				break;
		root=i;
		return root;
	}
	else
		return -1;
}
bool isomorphic(int R1,int R2)
{
	if(R1==-1&&R2==-1)
		return true;
	if((R1==-1&&R2!=-1)||(R1!=-1&&R2==-1))
		return false;
	if(tree1[R1].data!=tree2[R2].data)
		return false;
	if(tree1[R1].lchild==-1&&tree2[R2].lchild==-1)
		return isomorphic(tree1[R1].rchild,tree2[R2].rchild);
	if(tree1[R1].rchild==-1&&tree2[R2].rchild==-1)
		return isomorphic(tree1[R1].lchild,tree2[R2].lchild);
	if((tree1[R1].lchild!=-1&&tree2[R2].lchild!=-1)
	        &&(tree1[tree1[R1].lchild].data==tree2[tree2[R2].lchild].data))
		return isomorphic(tree1[R1].lchild,tree2[R2].lchild)
		       &&isomorphic(tree1[R1].rchild,tree2[R2].rchild);
}
void display(treenode tree[])
{
	for(int i=0; tree[i].data!='\0'; i++)
	{
		cout<<tree[i].data<<" ";
		cout<<tree[i].lchild<<" ";
		cout<<tree[i].rchild<<endl;
	}
	return;
}
int main()
{
	int root1=buildtree(tree1);
	int root2=buildtree(tree2);
	if(isomorphic(root1,root2))
		cout<<"YES"<<endl;
	else
		cout<<"No"<<endl;
	cout<<"tree1:"<<endl;
	display(tree1);
	cout<<"tree2:"<<endl;
	display(tree2);
	return 0;
}
