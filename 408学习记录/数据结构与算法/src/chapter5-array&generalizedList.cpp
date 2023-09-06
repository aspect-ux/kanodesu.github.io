#include <stdio.h> 
#include <iostream>
using namespace std;

// 数组的运算：初始化，销毁，根据下标获取，根据下表赋值 ；数组存储分为行存储和列存储 
// 什么是广义表？ 广义表是线性表的推广，也是n个元素的有限序列，但是与数组不同的是，
//                广义表存在子表,GL(i)也可能是一个广义表，递归定义，GL(1)是表头，其他是表尾 


//1. 三角矩阵：下三角，上三角，对称矩阵；拿下三角来说，只存储下方非0部分，压缩到n(n+1)/2大小的一维数组。
//2. 带状矩阵(Band Matrix)：参考 https://zhuanlan.zhihu.com/p/400460201 
//             - 带状矩阵的存储  - 带状矩阵的运算效率 
//3. 稀疏矩阵：0很多的矩阵 
//   - 顺序存储：<rowNum,columnNum,val>三元组存储形式 ，只能顺序读取 
//   - 十字链表：除了上述三元组，还包括指向行列的数组指针
// 					<rowNum,columnNum,val,nextRowPointer,nextColPointer>
//				总体来说，就是用两个数组实现压缩稀疏矩阵，一个存储行、一个存储列的第一个元素 
int main()
{
	return 0;
} 
