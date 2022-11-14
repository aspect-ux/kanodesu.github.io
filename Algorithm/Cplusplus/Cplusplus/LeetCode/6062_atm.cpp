#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
using namespace std;
class ATM {  //超出时间限制
    private:
     unordered_map<long,long> hash ;
     vector<int> s;
public:
    ATM() {
        this->hash = {{500,0},{200,0},{100,0},{50,0},{20,0}};
        this->s = {500,200,100,50,20};
    }
    void deposit(vector<int> banknotesCount){
        hash[20]+=banknotesCount[0];
        hash[50]+=banknotesCount[1];
        hash[100]+=banknotesCount[2];
        hash[200]+=banknotesCount[3];
        hash[500]+=banknotesCount[4];
    }
    vector<int> withdraw(int amount){
        vector<int> v(5,0);
        unordered_map<long,long> temp = hash;
        for(int i = 0;i < 5; i ++){
                int temp = amount / s[i];
                if(temp <= hash[s[i]]){
                      v[4 - i]+=temp;     //可以取那么取出加一
                      hash[s[i]]-=temp;        //别忘了减一
                    amount -= s[i]*temp;
                }
                else{
                    v[4-i]+=hash[s[i]];
                    amount -= hash[s[i]]*s[i];
                    hash[s[i]] = 0;
                    
                }
                if(amount == 0) break;
             //如果没有该面值直接退出   
        }
        if(amount!=0){
            //如果取款失败，恢复如初
            hash = temp;
             return{-1};
        }
        return  v;
    }
};
int main(){
    ATM* obj = new ATM();
    obj->deposit({0,1,0,3,0});
    vector<int> param_2 = obj->withdraw(600);
    cout<<param_2[0]<<endl;
    system("pause:");
    return 0;
}