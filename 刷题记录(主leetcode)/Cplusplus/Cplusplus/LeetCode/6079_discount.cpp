#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    string discountPrices(string sentence, int discount) {
        int invalid = 0,start = 0,num = 0, m = sentence.size(),len = 0;
        double res = 0.01;
        for(int i = 0 ;i < sentence.size(); i++){
            if(sentence[i] == ' '&& sentence[i + 1] == '$'){
                i +=2;
                start = i;              //start指向$+1
                while(sentence[i] != ' '){ //如果发现不合法
                    if(sentence[i] >=48 && sentence[i] <= 57){
                        num = sentence[i] - 48 + num*10;
                        len ++;
                    }
                    else if( sentence[i] == ' ') break;
                    else while(sentence[i]!=' '){
                        i++;
                        invalid = 1;
                        if(i == m) break;
                    }
                    i++;
                    if(i == m) break; //此时合法
                } //要么不合法，要么合法
               cout<<i<<' '<<invalid<<endl;
                    if(invalid) {  //不合法,那么不用改，i直接指到下一个空格
                        invalid = 0;
                        i --;
                        continue;
                    }
                    else {        //假如合法，就要 将打折后的价格放入，而不是原价
                        res = num - num * (discount*0.01);
                        string tmp =  to_string(res);
                        int x =0;
                        while(tmp[x]!='.'){
                            x++;
                        }
                        tmp = tmp.substr(0,x + 3);
                        sentence.replace(start,len,tmp);  //直接替换
                    }
                num = 0;
                len = 0;
            }
        }
        return sentence;
    }
};
/*if(sentence[i] == '$'){
                i++;
                while(sentence[i] != ' '){
                    if(sentence[i] <=57 && sentence[i] >= 48)
                    st.push(sentence[i]);
                    else invalid = 1;  //如果是数字和空格之外的字符，不合法
                    i++;
                }
                if(!invalid){ //如果合法
                    
                }
            }*/
int main(){
    system("pause:");
    return 0;
}