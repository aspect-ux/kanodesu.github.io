#include <iostream>
using namespace std;

// 图分为有向图和无向图，同时也分为有权图（网）和无权图 
// 总之一共有四种图 
 
#define MaxVertexNum 100	//顶点数目的最大值
typedef char VertexType;	//顶点的数据类型
typedef int EdgeType;	//带权图中边上权值的数据类型(+A[i] = 0/1) 又或者 只用于存储1，0表示边的存在与否 
typedef struct{
	VertexType Vext[MaxVertexNum];	//顶点表
	EdgeType Edge[MaxVertexNum][MaxVertexNum];	//邻接矩阵，边表
	int vexnum, arcnum;	//图的当前顶点数和弧树
}Graph;


int main()
{
	return 0;	
} 
