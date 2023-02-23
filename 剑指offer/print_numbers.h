/*
题目名称：
打印从1到最大的n位数

题目描述：
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
1. 用返回一个整数列表来代替打印
2. n 为正整数，0 < n <= 5

代码结构：
class Solution {
public:
    vector<int> printNumbers(int n) {
        // write code here
    }
};
*/

#ifndef ALGORITHM_CPP_PRINT_NUMBERS_H
#define ALGORITHM_CPP_PRINT_NUMBERS_H
#include "../common.h"

namespace PrintNumbers {
    class Solution {
    public:
        vector<int> printNumbers(int n) {
            int num = 1;
            while(n -- > 0) {
                num *= 10;
            }
            vector<int> result(num - 1);
            for(int i = 0; i < result.size(); i ++) {
                result[i] = i + 1;
            }
            return result;
        }

        void Test() {
            int n = 1;
            n = 2;
            n = 3;
            print(printNumbers(n));
        }
    };
}


#endif //ALGORITHM_CPP_PRINT_NUMBERS_H
