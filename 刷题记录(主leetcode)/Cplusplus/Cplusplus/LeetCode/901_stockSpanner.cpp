#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class StockSpanner {
public:
    stack<pair<int,int>> st;
    vector<int> a;
    StockSpanner() {
        st.push({-1,INT_MAX});
    }
    int next(int price) {
        a.push_back(price);
        while(price >= st.top().second) st.pop();
        int res = a.size() - st.top().first;
        st.push(price);
        return res;
    }
};
int main(){
    
    system("pause:");
    return 0;
}