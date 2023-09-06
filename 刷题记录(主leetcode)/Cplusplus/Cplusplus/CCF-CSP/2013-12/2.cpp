#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n = 3,ans = 0,j = 1;
	for (int i = 0; i < 11; i ++)
	{
		if (s[i] == '-')
		{
			continue;
		}
		else
		{
			ans += j * (s[i] - '0');
			j ++;
		}
		
	}
	int tmp = (s[s.size() - 1] - '0');
	if (s[s.size() - 1] == 'X') tmp = 10;
	if (ans%11 == tmp)
		cout<<"Right";
	else {
		if (ans%11 == 10)
			s[s.size() - 1] = 'X';
		else s[s.size() - 1] = (ans%11 + '0');
		cout<< s;
	}
	return 0;
} 
