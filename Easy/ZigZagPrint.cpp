/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"*/


class Solution {
public:
    string convert(string s, int numRows) {
        int i, j, step1, step2, len;
        string s_new = "";
        if(numRows == 1) return s;
        len = s.length();
        for(i=0;i<numRows;++i){
            step1 = (numRows-i-1)*2;
            step2 = 2*i;
            j = i;
            if(j<len)
                s_new += s.at(j);
            while(1){
                j += step1;
                if(j>=len) break;
                if(step1)
                    s_new += s.at(j);
                j += step2;
                if(j>=len) break;
                if(step2)
                    s_new += s.at(j);
            }
        }
        return s_new;
    }
};

