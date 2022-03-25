#### 删除链表的排名（data)第一第二个结点

```c++
void  FstAndSndValue(LinkList  L, void(*vi)(ElemType), int (*compare)(ElemType,ElemType) ) 
{
	LinkList p=L->next,pre=L,pindex;
	int max=0;
	int i=0,index;  //0对应首结点
	while(p){
		if(p->data.score>max){
			max=p->data.score;
			index=i;
			pindex=p;
		}
		i++;
		pre=pre->next;
		p=p->next;

	} //找到第一
	printf("第%d个学生成绩是第一名：\n",index+1);//输出
	output(pindex->data);
	int j=0;//删除第一
	pre=L;
	p=pre->next;
	while(p){
		if(index==j){//位置找到，删除
			pre->next=p->next;
		}
		j++;
		pre=pre->next;
		p=p->next;

	}
	
	i=0;//第二次初始化
	max=0;
	 p=L->next;
	 pre=L;
	 int index1;
	while(p){
		if(p->data.score>max){
			max=p->data.score;
			index1=i;
			pindex=p;
		}
		i++;
		pre=pre->next;
		p=p->next;

	} //找到第一
	printf("\n");
	if(index>index1)
	printf("第%d个学生成绩是第二名：\n",index1+1);//输出
	else 
	printf("第%d个学生成绩是第二名：\n",index1+2);//输出
	

	output(pindex->data);

	


	
	/********** End **********/
}//见头歌
```

