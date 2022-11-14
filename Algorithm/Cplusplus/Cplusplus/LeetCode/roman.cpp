#include<iostream>
#include<vector>
using namespace std;
//枚举
/*enum weekday_enum{
    Sunday,Monday,Tuesday,Wednesday
}*/
/*字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

*/
class Solution{
public:
string intToRoman(int num) {
   string a[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CX","M"};
   int b[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
   string res;
   for (int i=0;i<13;i++)
   {
       while(num<b[i+1]){
           num
       }
   }
      
  

}

};
int main()
{



    system("pause:");
    return 0;
}