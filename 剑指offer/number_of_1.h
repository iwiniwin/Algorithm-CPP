/*
题目名称：
二进制中1的个数

题目描述：
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

代码结构：
class Solution {
public:
     int  NumberOf1(int n) {

     }
};

补充：
正数的补码等于其原码
负数的补码等于其原码按位取反后（除了最高位）加1
右移之后 补0还是补1，取决于符号位，0为正，1为负
左移，默认都是补0
想法：
先按正数，算1的个数。然后处理负数的补码，不知道怎么处理。1的特点和用处，没有完全理解
n&n-1的也没想明白。没理解n&n-1的作用到底是什么
*/

#ifndef ALGORITHM_CPP_NUMBER_OF_1_H
#define ALGORITHM_CPP_NUMBER_OF_1_H
#include "../common.h"

namespace NumberOf1 {
    class Solution {
    public:
        /*
         * 解法1
         * 基本思路：
         * 对于本题，首先想到的是将目标数一直右移，然后将该数和1相与，计算1的个数，直到该二进制数为0为止
         * 但是考虑负数的情况，和正数右移最高位补0不同的是，负数右移最高位补1，这样就会有无数个1，导致循环无法停止
         * 既然将目标数右移和1与行不通，那么我们可以反过来。将1左移和目标数与
         * 将1不断左移（从最低位到最高位每一位依次是1，其他位是0），然后和目标数相与来求1的个数
         * 1的特点，就是最低位是1，其他位是0。数值和1与可以判断自己最低位的情况
         * 将1不断左移，可以让每位都是1（其他位是0），数值和它与可以判断自己每位的情况
         * 1在不断左移时，到最高位时时（一个较大的负数），移过最高位后就是0
         */
        int NumberOf1(int n) {
            int count = 0;
            int unit = 1;
            while(unit != 0) {
                if((unit & n) != 0) {
                    count ++;
                }
                unit <<= 1;
            }
            return count;
        }

        /*
         * 解法2
         * 基本思路：
         * 上面解法1的时间复杂度是O(n的位数)，n有所少位就要循环多少次。可以利用一个小技巧，降低算法的时间复杂度。
         * 对于数值n，将n - 1后再和n相与，得到的值相当于将n从右边数的第一个1变成0。
         * n的二进制表示中有多少个1，就能变多少次。时间复杂度可以优化为O(n中1的个数)
         * 详细介绍 https://www.cnblogs.com/iwiniwin/p/11058255.html
         */
        int NumberOf12(int n) {
            int count = 0;
            while(n != 0) {
                count ++;
                n &= n -1;
            }
            return count;
        }

        // -1  1111
        // -2  1110
        // -3  1101

        void Test() {
            int n = 10;
            n = -1;
//            print(NumberOf1(n));
            print(NumberOf12(n));
            print(-1 << 1);
        }
    };
}


#endif //ALGORITHM_CPP_NUMBER_OF_1_H
