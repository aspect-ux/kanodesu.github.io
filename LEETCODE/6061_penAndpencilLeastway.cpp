#include<iostream>
using namespace std;
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2){
        long long  tmp = total / cost1,tmp1;
        long long sum = 0;
        if(total >=cost1&& total >=cost2){
           for(long i = 0; i <= tmp; i++){
            long long tmp1 = (total - cost1*i) / cost2 + 1;
            sum += tmp1;
            //cout<<sum<<endl;
             }
        }
       else if(total < cost1 && total >= cost2){
            tmp1 = total / cost2 + 1;
            sum += tmp1;
        }
       else if(total >= cost1 && total < cost2){
            sum += tmp + 1;
        }
       else{
            sum = 1;
        }
       
        return sum;
    }
};
int main(){
    Solution s;
    cout<<s.waysToBuyPensPencils(1000,1,1);

    system("pause:");
    return 0;
}