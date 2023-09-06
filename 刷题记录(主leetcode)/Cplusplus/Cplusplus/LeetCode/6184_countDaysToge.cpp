#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> hash = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int compare(string a,string b){
        if(stoi(a.substr(0,2) + a.substr(3,2)) > stoi(b.substr(0,2) + b.substr(3,2)))
        return 1;
        else return 0;
    }
    int caculate(string a,string b){
        int ans = 0;
        int m1 = stoi(b.substr(0,2)),m2 = stoi(a.substr(0,2));
        int day1 = stoi( b.substr(3,2)),day2 = stoi(a.substr(3,2));
        if(m1 == m2) return day2 - day1 + 1;
        while(m1 < m2){
            ans += hash[m1] - day1 + 1;
            m1++;
            day1 = 1;
        }
        return ans + day2;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> hash;
         if(arriveAlice == arriveBob){
                if(leaveAlice == leaveBob)
                return caculate(leaveBob,arriveBob);
                else{
                    return compare(leaveBob,leaveAlice)?caculate(leaveAlice,arriveAlice):caculate(leaveBob,arriveAlice);
                }
            }
         
         if(leaveBob == leaveAlice){
             return compare(arriveBob,arriveAlice)?caculate(leaveAlice,arriveBob):caculate(leaveBob,arriveAlice);
            }
         
        if(compare(arriveAlice,arriveBob)){ // b < a
           
            if(compare(arriveAlice,leaveBob)) // 
            {
                return 0;
            }else if(compare(leaveBob,arriveAlice)&&compare(leaveAlice,leaveBob)){
                return caculate(leaveBob,arriveAlice);
            }else{
                return caculate(leaveAlice,arriveAlice);
            }

        }


        if(compare(arriveBob,arriveAlice)&&compare(leaveAlice,arriveBob)){ // b < a
            if(compare(leaveAlice,leaveBob)) // 
            {
                return caculate(leaveBob,arriveBob);
            }else if(compare(leaveBob,leaveAlice)){
                return caculate(leaveAlice,arriveBob);
            }
        }

        return 0;
    }   
};
int main(){
   
    
    system("pause:");
    return 0;
}