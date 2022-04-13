#### KMP算法

* next数组

  * 计算思路是next[1] =0,next[2] = 1,next[i] = length+1;

  *  a  b  a   a   b   c    a    c

     0   1   1  2  2    3   1    2

* 寻找第一次出现子串的位置

  

```c++
/*************************************************************
    date: February 2019
**************************************************************/
//////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strKMP.h"
/////////////////////////////////////////////////////

void GetNext(SString t, int next[])
{
    /********** Begin *********/
	next[1] = 0;
	next[2] = 1;
	//next[1] = 0;
	int i =2; //前
	int j =1; // 后
	while(i < t[0]){
		if(j == 1 || t[i] == t[j]){
			i++;
			j++;
			next[i] = j;  //
		
		}
		else j = next[j];

	}
        
	/********** End   *********/
}

int StrIndex_KMP(SString s,SString t, int pos)   
{
	int i,j,next[MAXSTRLEN+1];
	GetNext(t,next); 
	i=pos; j=1;
	while(i<=s[0]&&j<=t[0])
		if(s[i]==t[j]||j==0)
		{	i++; j++;	}
		else  j=next[j];  
	if(j>t[0]) return i-j+1; 
	else return 0; 
}

```

