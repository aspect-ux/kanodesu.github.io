#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
private:
    unordered_map<char,string> hash = {{'2',"abc"},{'3',"def"},{'4',"ghi"},
    {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
public:
    void dfs(int pos,string digits,vector<string> &ans,string res){
        //基线条件
        if(pos == digits.length()){
            ans.push_back(res);
            return;
        }
        char digit = digits[pos];
        string letters = hash.at(digit);
        for(char letter: letters){
            res.push_back(letter);  //将当前位置的某一个字符push
            dfs(pos+1,digits,ans,res);//等到第一次走到底时，已经将所有的字符串第一个字母放入//之后不断回溯
            res.pop_back();//开始回溯
        }
    }
    vector<string> letterCombinations(string digits) {
        //首先建一个哈希表存储数字对应的值
        //其次要想得到组合的总数，比如23，有ad,也有ae，无疑需要回溯
        //要选择第一个，第二个，第三个....最后一个，最后一个的第二个....最后一个。
        vector<string> ans;
        string res;
        if(digits.empty())return{};
        dfs(0,digits,ans,res);
        return ans;
    }
};
int main(){
	
	system("pause:");
	return 0;
} 