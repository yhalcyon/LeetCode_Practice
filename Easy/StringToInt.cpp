/*
Implement atoi to convert a string to an integer.
*/

class Solution {
public:
    int myAtoi(string str) {
        int i(0), tmp(0), len, sign(1);
        len = str.length();
        if(len==0) return 0;
        while(isspace(str.at(i))) ++i;
        if(str.at(i) == '-') {
            sign = -1; 
            ++i;
        }
        else if(str.at(i) == '+') {
            sign = 1; 
            ++i;
        } 
        while(i<len){
            if((str.at(i)<'0' || str.at(i)>'9')) break;
            if(str.at(i)>='0' && str.at(i)<='9'){
                if(i>8){
                    if(sign==1 && tmp>=(INT_MAX-(str.at(i)-'0'))/10) return INT_MAX;
                    if(sign==-1 && -1*tmp<=(INT_MIN+(str.at(i)-'0'))/10-1) return INT_MIN;
                }
                tmp = tmp*10 + str.at(i)-'0';
            }
            ++i;
        }
        if(tmp!=0) return sign*tmp;
        else return 0;
    }
};
