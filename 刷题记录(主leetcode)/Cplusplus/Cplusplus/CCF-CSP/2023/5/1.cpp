#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<vector<string>> hash;
	vector<int> ans;
	vector<string> tmp(8);
	// ≥ı ºªØ 
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < 8; j ++)
		{
			cin>>tmp[j];
		}
		
		int count = 1;
		for (int k = 0; k < hash.size(); k ++)
		{
			if (tmp == hash[k])
			{
				count ++;
			}	
		}
		hash.push_back(tmp);
		ans.push_back(count);
	} 
	
	for (auto c : ans)
	{
		cout<<c<<endl;
	}
	return 0;
} 
