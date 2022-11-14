#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
//思路：找到最后一个数字，将所有字母都试一遍，将结果1返回；开始回溯，找到倒数第二个数字，把第二个字母装填上
//然后调用backTrace,此时又找到最后一个数字....
/*
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.empty()) {
            return combinations;
        }
        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string combination;
        backtrack(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }

    void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) {
        if (index == digits.length()) {
            combinations.push_back(combination);
        } else {
            char digit = digits[index];
            const string& letters = phoneMap.at(digit);
            for (const char& letter: letters) {
                combination.push_back(letter); //将找到的那个按键里的内容push进string
                backtrack(combinations, phoneMap, digits, index + 1, combination);
                combination.pop_back();
            }
        }
    }
};
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/dian-hua-hao-ma-de-zi-mu-zu-he-by-leetcode-solutio/

*/
class Solution {
        private:
unordered_map<char,string> hash={{'2',"abc" },{'3',"def" },
                                {'4',"ghi" },{'5',"jkl"},
                                {'6',"mno" },{'7',"pqrs" },
                                {'8',"tuv" },{'9',"wxyz" }
                                };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;//输入
        vector<string> temp;

        for(int i = 0;i < 3; i++){
            for(int j = 0; j< 3; j++){
                temp += hash[digits[j]][i];
               // cout<<"temp="<<temp;
            }
            do{
                v.push_back(temp[0]);
            }while(next_permutation(temp.begin(),temp.end()));
            v.push_back(temp);
            temp = ""; //清零
        }
        return v;

    }

};
int main(){
    Solution s;
    vector<string> v;
    v=s.letterCombinations("234");
    for(int i = 0 ;i < v.size(); i++)
    cout<<v[i]<<endl;
    
    system("pause:");
    return 0;
}