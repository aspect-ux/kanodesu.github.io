#include<iostream>
#include<vector>
#include<set>
using namespace std;
class LUPrefix {
public:
    set<int> s;
    int num;
    LUPrefix(int n) {
        num = n;
    }
    
    void upload(int video) {
        s.insert(video);
    }
    
    int longest() {
        
    }
};

int main(){
    
    system("pause:");
    return 0;
}