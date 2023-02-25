/*
题目名称：
表示数值的字符串

题目描述：
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

代码结构：
class Solution {
public:
    bool isNumeric(string str) {
        // write code here
    }
};

想法：
常规遍历，找出数值的规则，有哪些情况
怎样记录前面的遍历结果，比如已经有一个+
前面去空格去+-，如果有e还可以有+-但不能有.
先判断空格+-整数/小数
有e继续判断科学计数
*/

#ifndef ALGORITHM_CPP_IS_NUMERIC_H
#define ALGORITHM_CPP_IS_NUMERIC_H

#include "../common.h"
#include <regex>

namespace IsNumeric {
    class Solution {
    public:
        /*
         * 解法1
         * 基本思路：
         * 常规想法，遍历字符串
         * 1. 字符是'0'-'9'
         * 2. 字符是'+'或'-'，只能出现在首位或'e'/'E'的后面
         * 3. 字符是'e'/'E'，只能出现一次，且不能在首尾
         * 4. 字符是'.'，只能出现一次，且不能在首位（可以在尾部），且不能在'e'/'E'之后出现
         * 5. 去除收尾空格
         */
        bool isNumeric(string str) {
            int index = 0;
            int len = str.length();
            while (index < len && str[index] == ' ') {
                index++;
            }
            while (len > 0 && str[len - 1] == ' ') {
                len--;
            }
            if (index == len) return false;
            if (str[index] == '+' || str[index] == '-') {
                index++;
            }
            if (index == len) return false;
            bool has_num = false;
            while (index < len && (str[index] >= '0' && str[index] <= '9')) {
                index++;
                has_num = true;
            }
            if (index < len && str[index] == '.') {
                index++;
            }
            if (!has_num && index == len) return false;
            while (index < len && (str[index] >= '0' && str[index] <= '9')) {
                index++;
                has_num = true;
            }
            if (has_num && index < len && (str[index] == 'e' || str[index] == 'E')) {
                index++;
                if (index == len) return false;
                if (str[index] == '+' || str[index] == '-') {
                    index++;
                }
                if (index == len) return false;
                while (index < len && (str[index] >= '0' && str[index] <= '9')) {
                    index++;
                }
            }

            return index == len;
        }

        /*
         * 解法2
         * 基本思路：
         * 使用正则表达式进行匹配
         */
        bool isNumeric2(string str) {
            return regex_match(str, regex("\\s*[+-]?(\\d*\\.\\d+|\\d+(\\.\\d*)?)([eE][+-]?\\d+)?\\s*"));
        }

        void Test() {
            string str = "  123.45e+6  ";
//            str = "1.2.3";
//            str = ".";
//            str = "    .2  ";
//            str = "  . ";
//            str = "1.2e+3  ";
//            str = " +1.2e-3  ";
//            str = "  .0e2  ";
//            str = "e1";
//            str = "+1";

            print(isNumeric(str));
            print(isNumeric2(str));
        }
    };
}


#endif //ALGORITHM_CPP_IS_NUMERIC_H
