#include <bits/stdc++.h>
using namespace std;

struct Window
{
	int leftX;
	int leftY;
	int rightX;
	int rightY;	
	string num;
};

struct ClickPoint
{
	int x;
	int y;
};
// 窗口数据和点击数据 
ClickPoint cp;
Window p;

bool isClicked(int x,int y,Window point)
{
	return x>=point.leftX&&x<=point.rightX&&y>=point.leftY&&y<=point.rightY;
}

int main()
{
	int M,N,res = 0;
	stack<Window> st,tmp,receive;
	queue<ClickPoint> click;
	queue<string> ans;

	cin>>N>>M;
	for (int i = 0; i < N; i ++)
	{
		cin>>p.leftX>>p.leftY>>p.rightX>>p.rightY;
		p.num = to_string(i+1);
		st.push(p);
	}
	
	for (int i = 0; i < M; i++)
	{
		cin>>cp.x>>cp.y;
		click.push(cp);
	}
	int x,y;
	for (int i = 0; i < M; i ++)
	{
		x = click.front().x,y = click.front().y;
		click.pop();
		tmp = st;
		while(receive.size()) receive.pop();
		for (int j = 0; j < st.size(); j ++)
		{
			// 如果在范围内就break,不在就继续验证下面的窗口，同时用栈保存pop的窗口 
			auto w = tmp.top();
			if (isClicked(x,y,w))
			{
				// 重新分配顺序：被点击的最上面，其他不变 
				ans.push(w.num);
				int t = receive.size();
				auto top = tmp.top();
				tmp.pop();
				for (int k = 0; k < t; k ++)
				{
					tmp.push(receive.top());
					receive.pop();
				}
				tmp.push(top);
				st = tmp;
				break;
			}
			else {
				receive.push(w);
				tmp.pop();
			}
			if (tmp.empty()) ans.push("IGNORED");
		}
		
	}
	int s= ans.size();
	for (int i = 0; i < s; i ++)
	{
		cout<<ans.front()<<endl;
		ans.pop();
	}
	return 0;
} 
