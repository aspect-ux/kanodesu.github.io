#include<stdio.h>

#include<string.h>
 
void Change(int P[],int x,int y){//将p数组中x位置的元素挪到y位置 
	//我们默认传参进来的 x大于 y  也就是默认往前挪  故不用判断x y大小关系了 
	int temp= P[x];
	while(x!=y){  //依次后移 
		P[x]=P[x-1];
		x--;
	} 
	P[y]=temp;
} 

int main()
{
    int PageNum[100];
	int Count[100];
	int Sum,MaxNum;
	memset(Count,0,sizeof(Count));
	scanf("%d",&Sum);//总数 
	scanf("%d",&MaxNum);//内存可存放页框数量 
	for(int i=1;i<=12;i++)  //初始化 
		scanf("%d",&PageNum[i]);	
	//页面调度
	int LackPage=0;
	int q=1,w=1;
	int flag=0;
	for(int i=1;i<=Sum;i++){
		if(i==1){  //第一个必然要直接加入 
			Count[PageNum[i]]++;
			w++; //此时为第一个 无需考虑内存已满情况 
			LackPage++;//缺页次数加1 
		}
		else{
			flag=0;
			for(int j=q;j<w;j++){ 
				if(PageNum[j]==PageNum[i]){//如果内存中已存在该页面
					flag=j;//记录该页面位置 
				}
			}
			if(flag!=0){ //内存中已存在该页面，需要把该页面挪到第一个位置 
				//ps:
				//若flag-q=0 说明已经是第一个位置了 就不用挪 
				//所以 小于0  需要挪 
				if( (flag-q) > 0){  
					Change(PageNum,flag,q);
				}
				q++;//挪完了，直接给他移出去 
				w++;//把新的加进来 （注意：这里不用判断内存满不满，因为根本没增加数量 
				Count[ PageNum[i] ]++; //该页面使用次数 +1 
			}
			else{//否则就是内存中没有该页面 
				LackPage++;//先把缺页次数+1
				//下面开始调页 
				if(flag==0 && (w-q) < MaxNum){//内存中没有该页面且内存未满 
					Count[ PageNum[w] ]++;//使用次数加1 
					w++; //直接加入内存
				}
				else{//内存中没有该页面且内存已经满了 
				     //注意：这里才是这个算法的核心，我们要比较使用次数 
					flag=q;//flga用于记录使用次数最少的页面位置 
					       //这里flag初试指向q是有意义的，不能乱改 
						   //如果大家使用次数都一样，那么q刚好是先进来的那个 
					for(int j=q+1;j<w;j++){//比较次数 
						if(Count[ PageNum[j] ] < Count[ PageNum[flag] ] ) 
							flag=j;//记录最小的 
					}
					if(flag==q){//说明使用次数都一样，那就选最先进来的 
						q++;
						w++;
						Count[ PageNum[i] ]++; //该页面使用次数 +1 
					}
					else{
						Change(PageNum,flag,q);//将使用次数最少的挪到最前面 
						q++;//淘汰使用次数最少的 
						w++;//加入新的
						Count[ PageNum[i] ]++; //该页面使用次数 +1 
					}
				} 
			}
		}
	} 
	printf("一共执行了 %d 个页面\n",Sum);
	printf("内存可以存放 %d 个页面\n",MaxNum);
	printf("一共缺页 %d 次\n",LackPage);
	printf("缺页率 %.3f \n",LackPage*1.0/Sum);



    int wait;
    printf("hello");
    scanf("%d",wait);
    return 0;
}