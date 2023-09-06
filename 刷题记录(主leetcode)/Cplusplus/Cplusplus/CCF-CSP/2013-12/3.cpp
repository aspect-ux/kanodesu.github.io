#include <bits/stdc++.h>
using namespace std;

#define ArrKeep 1
#define Flow 0
int main()
{
	int n,currentMax = 0,currentMin = INT_MAX,next = 0;
	vector<int> nums,keep;
	cin>>n;
	nums.resize(n);
	keep.resize(n,0);
	for (int i = 0; i < n; i ++)
	{
		cin>>nums[i];	
	} 
	
#ifdef ArrKeep
	// ����dp O(n2) ˼·��ö���Ե�ǰ���ν�β�������� 
	for (int i = 0; i < n; i ++)
	{
		for (int j = i; j >= 0; j--)
		{
			currentMin = min(nums[j],currentMin);
			int tmp = max(keep[j], currentMin * (i + 1 - j));
			keep[j] = tmp;
			//cout<<keep[j]<<' ';
		}
		//cout<<endl;
		currentMin = INT_MAX;
	}
	cout<<*max_element(keep.begin(),keep.end());
#elif Flow
	// �������� O(n2) ˼·��ö�ٵ�ǰ�߶� 
	int res = 0;
	for (int i = 0; i < n)
	{
		int l = i,r = i;
		while(r<n && nums[r] <= nums[r]) r++;
		while(l>=0 && nums[l] >= nums[l]) l--;
		res = max(res,nums[i] * (r - l - 1))
	}
	cout<<res<<endl;
#endif
	
	return 0;
} 
