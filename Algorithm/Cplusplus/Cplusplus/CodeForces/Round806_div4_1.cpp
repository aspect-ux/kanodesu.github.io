#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> v(n),ans(n);
    string s = "YES";
    for(int i = 0; i < n; i ++){
        cin>>v[i];
        int j;
        for(j = 0; j < 3; j ++){
            if(v[i][j] == s[j] || v[i][j] - 32 == s[j]){
                continue;
            }else break;
        }
        if(j!=3) ans[i] = "NO";
        else ans[i] = "YES";
    }
    for(int i = 0; i < n; i++){
        cout<<ans[i]<<endl;
    }

    system("pause:");
    return 0;
}