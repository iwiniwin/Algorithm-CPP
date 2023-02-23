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

想法：
常规思路，硬算，递归
怎么推断出有3用3 有2用2 得到乘积是最大值的
*/

#ifndef ALGORITHM_CPP_CUT_ROPE_H
#define ALGORITHM_CPP_CUT_ROPE_H

#include "../common.h"

namespace CutRope {
    class Solution {
    public:
        /*
         * 解法2，递归
         * 基本思路：
         * 常规想法，减去3以后，后面的结果递归去算
         */
        int cutRope(int number) {
            if (number <= 3) return number - 1;
            if (number == 4) return number;
            if (number <= 6) {
                return 3 * (number - 3);
            }
            return 3 * cutRope(number - 3);
        }

        /*
         * 解法2，贪婪算法
         * 基本思路：
         * 根据解法1列出的n的前几项，可以发现，对于每个大于4的值来说，都希望分出更多的3
         * 比如5 希望分成 2 * 3
         * 比如8 希望分成 5 * 3，再分成 2 * 3 * 3
         */
        int cutRope2(int number) {
            if (number <= 3) return number - 1;
            int ret = 1;
            while (number >= 5) {
                ret *= 3;
                number -= 3;
            }
            ret *= number;
            return ret;
        }

        /*
         * 解法3，动态规划
         * 基本思路：
         * 对于除n = 2和n = 3的特殊情况以外，使用dp数组记录前面的计算结果
         * 利用dp中的记录值，避免重复的计算
         */
        int cutRope3(int number) {
            if (number <= 3) return number - 1;
            vector<int> dp(number + 1);
            dp[2] = 2;
            dp[3] = 3;
            dp[4] = 4;
            int index = 5;
            while (index <= number) {
                dp[index ++] = dp[3] * dp[index - 3];
            }
            return dp[number];
        }

        void Test() {
            int number = 8;
            number = 2;
//            number = 3;
//            number = 5;
//            number = 6;  // 9
//            number = 7;  // 12
//            number = 9;  // 27
            number = 10;  // 36
//            number = 11;  // 54
//            print(cutRope(number));
//            print(cutRope2(number));
            print(cutRope3(number));
        }
    };
}


#endif //ALGORITHM_CPP_CUT_ROPE_H
