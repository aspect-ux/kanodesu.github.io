#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;

// x��ѡy�� 
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
	// ����Ĺؼ����ڷ��࣬0��1 a�࣬2��3 b��
	// �ȷ�a�࣬Ȼ���b��
	// ������2��{0��1}�������n - 2��{2��3} 
	// ������k�� {0��1}��0,1��һ��λ�ò��ܷţ�����0��t�������ȡ����t�ĸ���������1<=t<=k-1,2,3ͬ�� 
	// һ���� ��C(n-1,k) * ( k - 1) * (n - k - 1)  {k>=2&&k<=n-2}
	for (int i = 2; i < n - 1; i ++)
	{
		res = (res + C(n-1,i) * (i - 1)  * (n - i - 1)) % mod; 
	} 
	cout<<res;
	 
	return 0;
} 
