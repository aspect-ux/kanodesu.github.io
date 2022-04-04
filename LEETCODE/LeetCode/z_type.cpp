#include<bits/stdc++.h>
using namespace std;
/*class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int stop=0,n=0,index=0,index0=0;
        for(int i=0;i<numRows;i++)
        {
            while(1){
                res[n++]=s[index];
                index=2*(numRows-i)-2;
                if(numRows-2-index==0)
                index=index0+1;
                if(s[2*(numRows-index)-2]==){
                    stop=2*(numRows-index)-2;
                    break;
            }
                res[n++]=s[index];

            }
            
        }

        return res;
       
    }
};*/

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};



int main()
{
    string s="123456789";
    Solution a;
    cout<<a.convert(s,5);



    system("pause:");
    return 0;
}