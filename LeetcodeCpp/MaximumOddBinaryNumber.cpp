#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count1 = 0, count0 = 0;

        for(auto a:s){
            if(a=='1'){
                count1++;
            }
            else if(a=='0'){
                count0++;
            }
        }
        string ans = string(count1-1,'1') + string(count0,'0') + '1';
        return ans;
    }
};