#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        func(res, "", 0, 0, n);
        return res;
    }
    
    void func(vector<string> &res, string str, int l, int r, int n){
        if(l > n || r > n || r > l) return ;  //用来调用下一个递归选项
        if(l == n && r == n) {res.push_back(str); return;}
        func(res, str + '(', l+1, r, n);
        func(res, str + ')', l, r+1, n);
        return;
    }
};







*/
//给定一个数字确定所有有效的括号组合  parenthesis 括号 
//暴力法x  递归回溯 
class Solution{
	private: vector<string> ans;
	public:
		vector<string>
		generateParenthesis(int n){
			string cur;
			backtrack(n,0,0,cur,ans);
			return ans;
			
		} 
		void backtrack(int n,int left,int right,string cur,vector<string> &ans ){
			if(cur.length() == 2*n)//填满
			{
			ans.push_back(cur);
			return; 
		   }
			if(left < n)
			{
				cur.push_back('(');  // 递归里尽量别用++
		
				backtrack(n,left+1,right,cur,ans);
				cur.pop_back();
			}
			if(right < left)
			{
				cur.push_back(')');
			    backtrack(n,left,right+1,cur,ans);
			    cur.pop_back();
			}
		
		}
}; 
int main(){
	Solution s;
	vector<string> v;
	
	v = s.generateParenthesis(3);

	for(int i = 0;i < v.size(); i++){
		cout<<v[i]<<' ';
	}
	

	system("pause:");
	return 0;
} 