/*
题目名称：
正则表达式匹配

题目描述：
请实现一个函数用来匹配包括'.'和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

代码结构：
class Solution {
public:
    bool match(string str, string pattern) {
        // write code here
    }
};

想法：
常规遍历，匹配即可。WA了，Wrong Answer是由于只考虑了str走完，没考虑pattern也需要走完。
常规循环有点绕。怎么确定pattern走完？ 怎么让str和pattern都走完。还是要用递归
pattern走不走完重点在x*是否抵消，要用递归把抵消和不抵消的情况都走了
问题复杂的点在于x*的处理，所以要列出所有x*匹配的情况，分情况处理每一种，避免漏掉
动态规划，先要记录小问题的解。通过小问题怎么得到大问题的解。需要一种方式，或者一个公式。
*/

#ifndef ALGORITHM_CPP_MATCH_H
#define ALGORITHM_CPP_MATCH_H

#include "../common.h"

namespace Match {
    class Solution {
    public:
        /*
         * 解法1
         * 基本思路：
         * 当出现x*时，即任意一个字符加上'*'
         * 1. x*消耗0个字符，模式串后移两位，字符串不动
         * 2. x*消耗1个字符，模式串后移两位，字符串后移一位。这种情况可以被1和3组合完成，代码中省略了这步，用于减少递归深度，避免超时
         * 3. x*消耗多个字符，即匹配下一个字符，模式串不动，字符串后移一位
         * （注意，当这个'x'和字符串对应位的字符不相等时，x*只能等于消耗0个字符）
         * 未出现时
         * 1. 若模式串与字符串对应位字符相等，则都后移一位，匹配剩余的
         * 2. 若不相等，直接返回匹配失败
         * 注意特殊情况，当字符串已经走完，但模式串还未遍历时，需要支持这种情况下模式串继续遍历
         * 因为模式串可能还剩下x*这种，可以匹配0字符
         */
        bool match(string str, string pattern) {
            return match(str, 0, pattern, 0);
        }

        bool match(string str, int i, string pattern, int j) {
            if (i >= str.length() && j >= pattern.length()) return true;
            if (j >= pattern.length()) return false;

            if (j < pattern.length() - 1 && pattern[j + 1] == '*') {
                if (i < str.length() && (str[i] == pattern[j] || pattern[j] == '.')) {
                    return match(str, i, pattern, j + 2) || match(str, i + 1, pattern, j);
                } else {
                    return match(str, i, pattern, j + 2);
                }
            } else {
                if (i < str.length() && (str[i] == pattern[j] || pattern[j] == '.')) {
                    return match(str, i + 1, pattern, j + 1);
                } else {
                    return false;
                }
            }
        }

        /*
         * 解法2，动态规划
         * 基本思路：
         * 不能直接用[i,j]表示字符串i位置和模式串j位置的匹配情况，因为当字符串长度为0时，无法表示对应的匹配情况
         * 构建动态规划转移方程f[i,j]，表示字符串的前i个字符与模式串的前j个字符是否匹配
         * 对于不包含"*"的情况
         * f[i, j] = f[i - 1, j - 1] && (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.');
         * 表示前i个字符与模式串的前j个字符匹配的前提是，前i - 1个字符与前j - 1个字符匹配且第i个字符与第j个字符相等或第j个字符是"."
         * 对于包含"*"的情况
         * "*"表示出现0次时
         * f[i, j] |= f[i, j - 2];
         * 表示前i个字符与模式串的前j个字符匹配的前提是，前i个字符与前j - 2个字符匹配即可（相当于把x*忽略掉）
         * "*"表示出现1次或多次时
         * f[i, j] |= f[i - 1, j] && (str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.');
         * 表示前i个字符与模式串的前j个字符匹配的前提是，前i - 1个字符与前j个字符匹配且第i个字符与"*"前的字符相等或"*"前的字符是"."
         * 补充说明
         * f[0, 0]就表示空字符串与空模式串是否匹配
         * f[1, 1]就表示字符串第一个字符与模式串第一个字符是否匹配
         * f[str.Length, pattern.Length]就表示字符串str与模式串pattern是否匹配
         */
        bool match2(string str, string pattern) {
            vector<vector<bool>> result(str.length() + 1, vector<bool>(pattern.length() + 1, false));
            for (int i = 0; i <= str.length(); i++) {
                for (int j = 0; j <= pattern.length(); j++) {
                    if (j == 0) {
                        result[i][j] = i == 0;
                    } else if (j > 1 && pattern[j - 1] == '*') {
                        result[i][j] = result[i][j - 2];
                        if (i > 0 && (str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.')) {
                            result[i][j] = result[i][j] || result[i - 1][j];
                        }
                    } else {
                        result[i][j] = i > 0 && result[i - 1][j - 1];
                        result[i][j] = result[i][j] && (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.');
                    }
                }
            }
            return result[str.length()][pattern.length()];
        }

        void Test() {
            string str = "aaa";
//            str = "aad";
//            str = "a";
//            str = "aaab";
//            str = "aaaaaac";
//            str = "sflsifslfdslk";
//            str = "aaaaaaaaaaaaab";
            str = "basdfasdfasdfasdfas";
            string patter = "a*a";
//            patter = "c*a*d";
//            patter = ".*";
//            patter = "a*a*a*c";
//            patter = ".*.*.";
//            patter = "ab*";
//            patter = ".*a";
//            patter = "a*a*a*a*a*a*a*a*a*a*c";
            patter = "a.";
            patter = "basdf.*asdf.*asdf.*asdf.*s";

//            print(match(str, patter));
            print(match2(str, patter));
        }
    };
}


#endif //ALGORITHM_CPP_MATCH_H
