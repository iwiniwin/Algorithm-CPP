/*
题目名称：
调整数组顺序使奇数位于偶数前面

题目描述：
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。

代码结构：
class Solution {
public:
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
    }
};

想法：
1. 最简单，遍历两次，第一次取奇数第二次取偶数、
2. 冒泡算法变异，偶数往后冒，直到遇到偶数
*/

#ifndef ALGORITHM_CPP_RE_ORDER_ARRAY_H
#define ALGORITHM_CPP_RE_ORDER_ARRAY_H

#include "../common.h"

namespace ReOrderArray {
    class Solution {
    public:
        /*
         * 解法1
         * 基本思路：
         * 最直接的思路是再构建一个新的临时数组
         * 先遍历一遍原数组，把其中的奇数依次添加到新数组中
         * 再遍历一遍原数组把其中的偶数依次添加到新数组中
         * 时间复杂度为O(2n)
         */
        vector<int> reOrderArray(vector<int> &array) {
            vector<int> result(array.size());
            int index = 0;
            for (int i = 0; i < array.size(); ++i) {
                if(array[i] % 2 == 1) {
                    result[index ++] = array[i];
                }
            }
            for (int i = 0; i < array.size(); ++i) {
                if(array[i] % 2 == 0) {
                    result[index ++] = array[i];
                }
            }
            return result;
        }

        /*
         * 解法2
         * 基本思路：
         * 解法1用到了临时数组，空间复杂度是O(n)，某些情况下可能希望空间复杂度越低越好。
         * 解法2虽然时间复杂度提高了，但降低了空间复杂度，不再需要额外的空间。
         * 基本思路是遍历原数组，如果遇到了奇数元素，就将该元素向前移动，该元素前面的偶数元素都依次向后移动。
         * 可以这样理解，每发现一个奇数时，就将这个奇数移动到了它最终应该在的位置上。
         */
        vector<int> reOrderArray2(vector<int> &array) {
            for (int i = 1; i < array.size(); i++) {
                if (array[i] % 2 == 1) {
                    int j = i;
                    int target = array[j];
                    while(j > 0 && array[j - 1] % 2 == 0) {
                        array[j --] = array[j - 1];
                    }
                    array[j] = target;
                }
            }
            return array;
        }

        void Test() {
            vector<int> array = {1, 2, 3, 4};
            array = {2, 4, 6, 5, 7};
//            array = {1, 3, 5, 6, 7};
//            array = {4, 2};
//            print(reOrderArray(array));
            print(reOrderArray2(array));
        }
    };
}


#endif //ALGORITHM_CPP_RE_ORDER_ARRAY_H
