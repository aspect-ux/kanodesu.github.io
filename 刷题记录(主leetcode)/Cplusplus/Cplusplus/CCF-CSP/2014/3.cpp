#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> SplitBySpace(const string& s)
{
	vector<string> split;
	string tmp = "";
	for (int i = 0 ; i < s.size(); i ++)
	{
		if (s[i] != ' ')
			tmp += s[i];
		else {
			split.push_back(tmp);
			tmp = "";
		}
	}
		
} 

int main()
{
	int N;
	vector<string> instruct,ans;
	unordered_map<char,int> hash; // 对单个选项进行标记，是否需要带参 
	string format,tmp;
	
	cin>>format;
	cin>>N;
	
	// 输入指令列表
	instruct.resize(N);
	for (int i = 0; i < N; i ++)
	{
		cin>>instruct[i];
		cout<<"?";
	} 
	
	// 解析format
	int m = format.size();
	for (int i = 0; i < m; i ++)
	{
		if (i != m - 1 && format[i+1] == ':')
		{
			hash[format[i]] = 1;
			i++;
		}
	} 
	/*
	// 循环解析单个命令 
	for (int i = 0; i < N; i ++)
	{
		// 使用空格split字符串
		auto insArr = SplitBySpace(instruct[i]);
		string singleAns = "";
		for (int j = 1; j < insArr.size(); j ++)
		{
			auto s = insArr[j];
			if (s.empty()) break;
			if (s[0] != '-' || (s[i]>'9'&&s[i]<'0')) break;
			singleAns += s + ' ';
		}
		ans.push_back(singleAns);
	}
	
	// 输出结果
	int k = ans.size();
	for (int i = 0; i < k; i ++) 
	{
		cout<<ans[i];
	}*/
	return 0;
} 
