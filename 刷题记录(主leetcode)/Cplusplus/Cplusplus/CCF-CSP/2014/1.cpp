#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,res = 0,tmp;
	unordered_set<int> hash;
	cin>>n;
	for (int i = 0; i < n; i ++)
	{
		cin>>tmp;
		if (hash.find(-tmp)==hash.end()) hash.insert(tmp);
		else res ++;
	}
	cout<<res;
	return 0;
} 
