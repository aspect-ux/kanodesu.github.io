#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;
vector<vector<ll>> cross(vector<vector<ll>> left,vector<vector<ll>> right)
{
	int n = left.size(),d = right[0].size();
	vector<vector<ll>> ans(n,vector<ll>(d));
	vector<ll> currentRow;
	for (int i = 0; i < n; i ++)
	{
		currentRow = left[i];
		for (int j = 0; j <d; j++)
		{
			ll tmp = 0;
			for (int k = 0; k <right.size(); k++)
			{
				tmp += currentRow[k] * right[k][j];
			}
			ans[i][j] = tmp;
		}
	}
	return ans;
}

vector<vector<ll>> dot(vector<int> W,vector<vector<int>> Matrix)
{
	int n = Matrix.size(),d = Matrix[0].size();
	vector<vector<ll>> res(n,vector<ll>(d));
	
	for (int j = 0; j <n; j++)
	{
		for (int k = 0; k <d; k++)
		{
			res[j][k] = Matrix[j][k] * W[j];
		}
	}
	return res;
}
int main()
{
	int n,d;
	cin>>n>>d;
	vector<vector<int>> Q(n,vector<int>(d));
	vector<vector<ll>> inverse_K(d,vector<ll>(n)),V(n,vector<ll>(d));
	vector<int> W(n);
	
	// 矩阵输入
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < d; j ++)
		{
			cin>>Q[i][j];
		}	
	}
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < d; j ++)
		{
			cin>>inverse_K[j][i];
			//K[i][j] = inverse_K[j][i];
		}	
	} 
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < d; j ++)
		{
			cin>>V[i][j];
		}	
	} 
	for (int i = 0; i < n; i ++)
		cin>>W[i];

 	// 计算输出
 	vector<vector<ll>> ans;
	//ans = cross(dot(W,cross(Q,inverse_K)),V); 这种顺序只有70分 
	ans = cross(dot(W,Q),cross(inverse_K,V));
	for (int i = 0; i < ans.size(); i ++)
	{
		for (int j = 0; j < ans[0].size(); j ++)
		{
			cout<< ans[i][j];
			if (j!=d-1) cout<<' ';
		}
		cout<<endl;
	}
	return 0;
} 
