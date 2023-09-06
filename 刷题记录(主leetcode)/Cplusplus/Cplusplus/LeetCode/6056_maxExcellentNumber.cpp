#include<iostream>
using namespace std;
// We're going to use enum method
class Solution {
public:
    string largestGoodInteger(string num){
        for(int i = 9; i >= 0; i--){
            string s = to_string(i*100 + i*10 + i);
            if(s == "0") s="000";  //remember to take 0 into account
            for(int j = 0; j < num.length() - 2; j++){
                if(s == num.substr(j,3)){
                    return s;
                }
            }
        }
        return "";
        
    }
};
int main(){
    Solution s;
    cout<<s.largestGoodInteger( "6777133339");
    system("pause:");
    return 0;
}