#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;

// x中选y个 
int comm(int x,int y){
    int num1 = x,num2 = y,num = 0;
    for(int i=1;i<y;i++)
    {
        num1 = num1 * (x - i) % mod;
        num2 = num2 * (y - i) % mod;
    }
    num = num1/num2 % mod;
    return num;
}
int C(int n,int k){
	if(k > n)
		return 0;
	else if(n == k||k==0)
		return 1;
	else
		return comm(n-1,k) + comm(n-1,k-1);
} 
int main()
{
	int n;
	cin>>n;
	
	ll res = 0;
	// 这题的关键在于分类，0，1 a类，2，3 b类
	// 先放a类，然后放b类
	// 至少有2个{0或1}；最多有n - 2个{2或3} 
	// 假设有k个 {0或1}，0,1第一个位置不能放，其中0有t个，结果取决于t的个数的种类1<=t<=k-1,2,3同理 
	// 一共有 ΣC(n-1,k) * ( k - 1) * (n - k - 1)  {k>=2&&k<=n-2}
	for (int i = 2; i < n - 1; i ++)
	{
		res = (res + C(n-1,i) * (i - 1)  * (n - i - 1)) % mod; 
	} 
	cout<<res;
	 
	return 0;
} 
