#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    // vector<int> station = {2,7,3,6};
    // int d = 7;
    vector<int> station,ans;
    int b = 0,d = 0;
    cout<<"Input station num:"<<endl;
    cin>>b;
    int tmp;
    cout<<"input distance arr:"<<endl;
    for (int i = 0; i < b; i ++) {cin>>tmp;station.push_back(tmp);}
    cout<<"input max travel dis:"<<endl;
    cin>>d;
    tmp = d;
    for (int i = 0; i < b; i ++) {
        d -= station[i];
        if (d < 0) {ans.push_back(i);d = tmp;d -= station[i];}
    }
    cout<<"YOU NEED REFUEL IN:"<<endl;
    for (int c:ans) cout<<c<<' ';

    system("pause:");
    return 0;
}