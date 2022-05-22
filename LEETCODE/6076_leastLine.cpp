#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) { //用斜率不太好搞，干脆用Pair
        pair<long,long> pivot = {(stockPrices[1][1] - stockPrices[0][1])/(stockPrices[1][0] - stockPrices[0][0]),
        (stockPrices[1][1] - stockPrices[0][1])%(stockPrices[1][0] - stockPrices[0][0])};
        int cnt = 1;
        sort(stockPrices.begin(),stockPrices.end());
        for(long i = 1; i < stockPrices.size() - 1; i++){
            pair<long,long> tmp = {(stockPrices[i+1][1] - stockPrices[i][1])/(stockPrices[i+1][0] - stockPrices[i][0]),
        (stockPrices[1+i][1] - stockPrices[i][1])%(stockPrices[i+1][0] - stockPrices[i][0])};
            if(pivot == tmp) continue;
            pivot = tmp;
            cnt ++;
        }
        return cnt;
    }
};
int main(){
    cout<<-3%2<<' '<<-3/2<<endl;
    system("pause:");
    return 0;
}