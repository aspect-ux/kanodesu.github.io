#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n),ans(n);
    for(int i = 0; i < n; i ++){
        cin>>v[i];
    }
    //--------------------------
    int sum = v[0],ugly = 0;
    for (int i = 1; i < n; i ++) {
        if (sum == v[i]) {
            ugly = 1;
            swap(v[i],v[i - 1]);
        }
        sum += v[i];
    }
    if (ugly) {
        cout<<"YES"<<endl;
        for (auto c : v) cout<<c<<' ';
    }
    else cout<<"NO"<<endl;

    //--------------------------

    system("pause:");
    return 0;
}