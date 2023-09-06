#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        unordered_map<string,int> hash;
        vector<string> tmp;
        vector<int> ans;
        int cnt = 0;
        vector<vector<string>> record;
        for(int i = 0; i < n; i ++){
            tmp = prefix(words[i]);
            record.push_back(tmp);
            for(auto c : tmp){
                hash[c] ++;
            }
        }
        for(int i = 0; i < n; i ++){
            for(auto c : record[i]){
                cnt += hash[c];
            }
            ans.push_back(cnt);
            cnt = 0;
        }
        return ans;
    }
    vector<string> prefix(string str)
    {
        int len = str.length();  //获取字符串的长度
        string s = "";  //定义变量来存储每个元素
        vector<string> result(len);  //定义数组来存放前缀的元素们
        for (int i = 0; i < len; i++) {
            s = s + str[i];  //每个元素都是上一个元素往后再加一个字符
            result[i] = s;  //将元素存放进准备好的数组容器中
        }
        return result;  //返回结果数组
    }
};

int main(){
    
    system("pause:");
    return 0;
}
