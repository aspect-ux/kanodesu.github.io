#include<iostream>
#include<stack> 
#include<string>
#include<algorithm>
#include<string.h>
#include<cstring>
using namespace std;
//栈----后缀表达式 
int main(){
	//将中缀表达式转化成便于计算的后缀表达式
	//运算符放到st中，数字放到 pivotexp中 
	//优先级高的运算符靠近栈顶 
	//+，-   */   （） 
	stack<char> st;
	char s[20];
    char pivotexp[50];
	int i= 0,exp=0;
	cin.getline(s,10);
	while(s[i]!='\0'){
		
		if(s[i] == '+'||s[i]=='-' ){
            if(st.empty()) st.push(s[i]);

			else if(st.top() == '/'||st.top()=='*'){
				pivotexp[exp++] = st.top();
               
				st.pop();
				st.push(s[i]);
			}
			else if(st.top() == '('){
				st.push(s[i]);
			}
		}
		else if(s[i] == '('){
			st.push(s[i]); //左括号入栈 
		}
		else if(s[i] == ')')  //如果是右括号将所有左括号前的符号全部出栈到pivotexp 
		{
				while(st.top()!='('){
					pivotexp[exp++]=st.top();
					st.pop();
			}
			st.pop();
		}
		else if((s[i] == '*'|| s[i] == '/')){//如果是乘除,那就直接放
        st.push(s[i]);

            
		} 
		else if(s[i]>='0' && s[i] <='9'){					//数字的话就放入结果串 
        
			while(s[i]>='0' && s[i] <='9')
			pivotexp[exp++]=s[i++];
			i--;  //将非一位数全部打入
			pivotexp[exp++]='#';//数与数之间用#间隔
           
		}
		i++;   //指针后移
	}
    int n=0;
    while(!st.empty()){
        pivotexp[exp++] = st.top();
        st.pop();
    }
    pivotexp[exp] = '\0';
    for(int i = 0 ;i < exp;i++){
        cout<<pivotexp[i];
    }

    cout<<endl;
	//以上生成了一个后缀表达式，以下开始对这个后缀表达式进行计算
	//后缀表达式没有括号
	int ans,b; //
	stack<int> st1;
	for(int i = 0 ;i < exp; i++){
		b = 0;                                        //b每轮更新
		if(pivotexp[i] >='0' &&pivotexp[i] <='9'){ //如果是数字就对前两个操作数进行运算
			while(pivotexp[i] != '#'){  
				b += pivotexp[i++] -48 + 10*b;
                st1.push(b);  //数字入栈
                 
			}
		}

        else if(pivotexp[i] == '*'){   //如果做乘法
        //将前两个数pop出来，做完运算在push进去
        int op1 = st1.top();
        st1.pop();
        int op2 =st1.top();
        st1.pop();
        st1.push(op1*op2);
        cout<<st1.top()<<endl;
        }
         else if(pivotexp[i] == '/'){   //如果做乘法
        //将前两个数pop出来，做完运算在push进去
        int op1 = st1.top();
        st1.pop();
        int op2 =st1.top();
        st1.pop();
        st1.push(op2/op1); //op1先出栈为右运算符
        }
         else if(pivotexp[i] == '+'){   //如果做乘法
        //将前两个数pop出来，做完运算在push进去
      
        int op1 = st1.top();
     
        st1.pop();
        int op2 =st1.top();
        st1.pop();
        st1.push(op1+op2);
      cout<<st1.top()<<endl;
     
        }
         else if(pivotexp[i] == '-'){   //如果做减法
        //将前两个数pop出来，做完运算在push进去
        int op1 = st1.top();
        st1.pop();
        int op2 =st1.top();
        st1.pop();
        st1.push(op2-op1);
        cout<<st1.top()<<' '<<st1.size()<<endl;
         // if(st1.size()==1) cout<<"计算结果为:"<<st1.top()<<endl;
       
        }
      //  if(st1.size()==1) cout<<"计算结果为:"<<st1.top()<<endl;
       
	
	}
    int a = st1.top();
    cout<<"output:"<<a<<endl;
     //cout<<"计算结果为:"<<st1.top()<<endl;
	system("pause:");


return 0;	
} 

