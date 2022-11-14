#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int,int> hash;
        for(int i = 0; i < num.size(); i ++){
            hash[num[i] - 48] ++;
        }
        for(int i = 0; i < num.size(); i ++){
           if(hash[i] == (num[i] - 48)){
               continue;
           }
           else {
               return false;
           }
        }
        return true;  
    }
};
int main(){
    system("pause:");
    return 0;
}