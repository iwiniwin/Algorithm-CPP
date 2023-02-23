/*
题目名称：
剪绳子

题目描述：
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为k[0],k[1],...,k[m]。
请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

输入描述：
输入一个数n，意义见题面。（2 <= n <= 60）

输出描述：
输出答案。

代码结构：
class Solution {
public:
    int cutRope(int number) {

    }
};

补充：
动态规划求解问题的特征：
1. 求问题的最优解，整体的最优解依赖于子问题的最优解
2. 从上往下分析问题，从下往上求解问题
*/

#ifndef ALGORITHM_CPP_CUT_ROPE_H
#define ALGORITHM_CPP_CUT_ROPE_H
#include "../common.h"

namespace CutRope {
    class Solution {
    public:
        int cutRope(int number) {

        }

        void Test() {
            print("test");
        }
    };
}


#endif //ALGORITHM_CPP_CUT_ROPE_H
