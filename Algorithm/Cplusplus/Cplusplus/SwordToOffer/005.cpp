#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //暴力超时了捏
    bool notContain(string a,string b)
    {
        int m = a.size(),n = b.size();
        if (m < n) swap(a,b);
        for (int i = 0; i < b.size(); i ++) {
            for (int j = 0; j < a.size(); j ++) {
                if (b[i] == a[j]) return false;
            }
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        int ans = 0;
        for (int i = 0; i < words.size(); i ++) {
            for (int j = i + 1; j < words.size(); j ++) {
                if (notContain(words[i],words[j])) {
                    int tmp = words[i].length() * words[j].length();
                    ans = max(ans,tmp);
                }
            }
        }
        return ans;
    }
};
class Solution_1 {
public:
    //显然四重循环不行，但是如果利用位运算将结果以另一种方式记录下来
    //转化成二重循环就行
    int maxProduct(vector<string>& words) {
        int n = words.size(),ans = 0;
        vector<int> mask(n);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < words[i].size(); j ++) {
                //这个式子的关键在于,将字符串以二进制数的形式保存,如果使用|运算,就可以正确保存
                mask[i] |= (1<<(words[i][j] - 'a'));
            }
        }
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                if ((mask[i]&mask[j]) == 0) //记得加括号，&优先级有点问题
                {
                    int tmp = words[i].length() * words[j].length();
                    ans = max(ans,tmp);
                }
            }
        }
        return ans;
        //另外如果需要优化，则是在第一次二重中
        //对不同字符串，但组成字符相同 进行去除
    }
};