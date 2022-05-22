#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i = 1; i < words.size(); i++){
            string tmp = words[i],pivot = words[i - 1];
            sort(tmp.begin(),tmp.end());
            sort(pivot.begin(),pivot.end());
            if(tmp == pivot){
                 words.erase(words.begin() + i,words.begin()+ i);
                 i --;
            }
        }
        return words;
    }
};
int main(){

    system("pause:");
    return 0;
}