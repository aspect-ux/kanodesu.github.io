#include<iostream>
#include<unordered_map>
using namespace std;
/*
"the quick brown fox jumps over the lazy dog"
"vkbs bs t suepuv"
*/
class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> hash;
        char tmp = 'a';
        //制表
        for(char c : key){
            if(hash.find(c)!=hash.end() || c == ' '){ //如果找到了,那么不需要重复，跳过
                continue;
            }
            tmp ++;
            hash[c] = tmp;
        }
        //译码
        for(int i = 0; i < message.size(); i++){
            if(message[i] == ' ') continue;
            message[i] = hash[message[i]];
        }
        return message;
    }
};
int main(){
   
    system("pause:");
    return 0;
}