#include <bits/stdc++.h>

int main()
{
	std::unordered_map<int,int> hash;
	std::vector<int> arr;
	int maxCount = 0, n, ans = INT_MAX,tmp;
	std::cin>>n;
	for (int i = 0 ; i < n; i ++)
	{
		std::cin>>tmp;
		hash[tmp]++;
		maxCount = std::max(maxCount,hash[tmp]);
	}

	for (auto c : hash)
	{
		if (c.second == maxCount)
			ans = std::min(ans,c.first);
	}
	std::cout<<ans;
	return 0;
} 
