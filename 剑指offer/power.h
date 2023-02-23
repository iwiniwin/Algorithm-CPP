/*
题目名称：
数值的整数次方

题目描述：
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0

代码结构：
class Solution {
public:
    double Power(double base, int exponent) {

    }
};

想法：
1. 常规乘法
2. 快速幂
*/

#ifndef ALGORITHM_CPP_POWER_H
#define ALGORITHM_CPP_POWER_H
#include "../common.h"

namespace Power {
    class Solution {
    public:
        /*
         * 解法1
         * 基本思路：
         * 最直接的思路，计算m的n次方，则将m连乘n次即可
         * 注意处理特殊情况：
         * 非0数的0次方等于1
         * 当指数为负数时的结果，相当于用1除以指数为正数时的结果
         */
        double Power(double base, int exponent) {
            if(base == 0) return 0;
            if(exponent < 0) {
                exponent = -exponent;
                base = 1 / base;
            }
            double ret = 1;
            while(exponent -- > 0) {
                ret *= base;
            }
            return ret;
        }

        /*
         * 解法2，递归
         */
        double Power2(double base, int exponent) {
            if(base == 0) return 0;
            if(exponent == 0) return 1;
            if(exponent < 0) {
                exponent = -exponent;
                base = 1 / base;
            }
            return base * Power2(base, exponent - 1);
        }

        /*
         * 解法3，快速幂
         * 基本思路：
         * 求解整数m的n次方，一般是m ^ n = m * m * m .....，连乘n次，算法复杂度是O(n)
         * 这样的算法效率太低，我们可以通过减少相乘的次数来提高算法效率，即快速幂
         * 对于n我们可以用二进制表示，以14为例，14 = 1110
         * m ^ (14) = m ^ (1110) = m ^ (2 ^ 3 * 1) * m ^ (2 ^ 2 * 1) * m ^ (2 ^ 1 * 1) * m ^ (2 ^ 0 * 0)
         * = m ^ (8 * 1) * m ^ (4 * 1) * m ^ (2 * 1) * m ^ (1 * 0) = m ^ 8 * m ^ 4 * m ^ 2 * 1
         * 可以发现这样的规律，指数n的二进制从低位到高位依次对应底数m的1次方，2次方，4次方，8次方...，
         * 当该二进制位是1的时候，则乘以底数对应的次方数，如果该二进制位是0，则表示乘以1
         */
        double Power3(double base, int exponent) {
            if(base == 0) return 0;
            if(exponent < 0) {
                exponent = -exponent;
                base = 1 / base;
            }
            double ret = 1;
            while(exponent > 0) {
                if((exponent & 1) == 1) {
                    ret *= base;
                }
                base *= base;
                exponent >>= 1;
            }
            return ret;
        }

        void Test() {
            double base = 2;
//            base = 2.1;
            int exponent = 3;
            exponent = -2;
//            print(Power(base, exponent));
            print(Power2(base, exponent));
//            print(Power3(base, exponent));
        }
    };
}


#endif //ALGORITHM_CPP_POWER_H
