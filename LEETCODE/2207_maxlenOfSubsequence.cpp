#include<iostream>
using namespace std;
//注意用long是为了防止输入的字符串太大
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long ans = 0;
        long p1 = 0;
        long p2 = 0;
        //遍历一遍，记录p[0]p[1]个数，第二个循环，是p[0]p[1]则个数减1，如此O(2n)再累加就可以得到结果
        for(int i = 0;i < text.length(); i++){
            if(text[i] == pattern[0]){
                p1++;
            }
            else if(text[i] == pattern[1])
            p2++;
            else{
                continue;
            } 
        }
        if(pattern[0] == pattern[1]){
                     p2 = p1;
                 }
        long temp = 0;
        long tmpP2 = p2;  //要注意p2本身不能改变因为后面要用到
        
        for(int i = 0;i < text.length(); i++){
             if(text[i] == pattern[0]){
                if(pattern[0] == pattern[1]){ //在连个字符相同时，就只会运行第一个判断
                    tmpP2--;
                }
                 temp += tmpP2;
                
             }
              else if(text[i] == pattern[1]){
                  tmpP2--;
              }
              else continue;

        }
       // cout<<"p2:"<<p2<<"p1:"<<p1<<endl;
        return max(temp+p2,temp+p1);//返回最大的，有p1个pattern[0],p2个pattern[1];
    }
};
int main(){
    Solution s;
    cout<<s.maximumSubsequenceCount("vnedkpkkyxelxqptfwuzcjhqmwagvrglkeivowvbjdoyydnjrqrqejoyptzoklaxcjxbrrfmpdxckfjzahparhpanwqfjrpbslsyiwbldnpjqishlsuagevjmiyktgofvnyncizswldwnngnkifmaxbmospdeslxirofgqouaapfgltgqxdhurxljcepdpndqqgfwkfiqrwuwxfamciyweehktaegynfumwnhrgrhcluenpnoieqdivznrjljcotysnlylyswvdlkgsvrotavnkifwmnvgagjykxgwaimavqsxuitknmbxppgzfwtjdvegapcplreokicxcsbdrsyfpustpxxssnouifkypwqrywprjlyddrggkcglbgcrbihgpxxosmejchmzkydhquevpschkpyulqxgduqkqgwnsowxrmgqbmltrltzqmmpjilpfxocflpkwithsjlljxdygfvstvwqsyxlkknmgpppupgjvfgmxnwmvrfuwcrsadomyddazlonjyjdeswwznkaeaasyvurpgyvjsiltiykwquesfjmuswjlrphsdthmuqkrhynmqnfqdlwnwesdmiiqvcpingbcgcsvqmsmskesrajqwmgtdoktreqssutpudfykriqhblntfabspbeddpdkownehqszbmddizdgtqmobirwbopmoqzwydnpqnvkwadajbecmajilzkfwjnpfyamudpppuxhlcngkign"
,"rr");
    system("pause:");
    return 0;
}