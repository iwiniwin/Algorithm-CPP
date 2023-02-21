/*
题目名称：
替换空格

题目描述：
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

代码结构：
class Solution {
public:
    string replaceSpace(string s) {
        // write code here
    }
};

想法：
逐字符复制字符串，遇到空格复制%20
*/

#ifndef ALGORITHM_CPP_REPLACE_SPACE_H
#define ALGORITHM_CPP_REPLACE_SPACE_H
#include <iostream>
#include <string>

using namespace std;

namespace ReplaceSpace {
    class Solution {
    public:
        /*
         * 解法基本思路：
         * 这道题比较简单，就是遍历该字符串每一个字符进行复制，遇到空格就复制成%20
         */
        string ReplaceSpace(string s) {
            string str = "";
            for(int i = 0; i < s.length(); i ++) {
                if(s[i] == ' ') {
                    str += "%20";
                } else {
                    str += s[i];
                }
            }
            return str;
        }

        void Test() {
//            string s = "We Are Happy";
            string s = " ";
            std::cout << ReplaceSpace(s) << endl;
        }
    };
}


#endif //ALGORITHM_CPP_REPLACE_SPACE_H
