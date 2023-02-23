/*
题目名称：
旋转数组的最小数字

题目描述：
有一个长度为 n 的非降序数组，比如[1,2,3,4,5]
将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组
比如变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。请问，给定这样一个旋转数组，求数组中的最小值。
NOTE：给出的所有元素都大于等于0，若数组大小为0，请返回0。

代码结构：
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {

    }
};

想法：
找到第一个不是不递增的数据就行
应该没其他解法了吧
双指针？有序性查找就应该想到二分查找  忘记二分查找是怎么跳出的了，不用跳出
*/

#ifndef ALGORITHM_CPP_MIN_NUMBER_IN_ROTATE_ARRAY_H
#define ALGORITHM_CPP_MIN_NUMBER_IN_ROTATE_ARRAY_H

#include "../common.h"

namespace MinNumberInRotateArray {
    class Solution {
    public:
        /*
         * 解法1
         * 基本思路：
         * 对于非减数组来说，数组左边的元素一定小于等于数组右边的元素。
         * 当对非减数组进行旋转后（把数组最开始的元素搬到末尾），
         * 则在遍历过程中可能会出现左边的元素反而小于右边的元素，当第一次出现这种情况时，
         * 一定是原非减数组的开头，即整个数组的最小元素。
         */
        int minNumberInRotateArray(vector<int> rotateArray) {
            if (rotateArray.size() == 0) return 0;
            for (int i = 0; i < rotateArray.size() - 1; i++) {
                if (rotateArray[i] > rotateArray[i + 1]) {
                    return rotateArray[i + 1];
                }
            }
            return rotateArray[0];
        }

        /*
         * 解法2
         * 基本思路：
         * 对于有序数组的查找问题，首先想到的就是二分查找。
         * 本题是非递减数组的旋转数组，仍具有一定的顺序性，所以稍微修改一下二分查找仍然可以解题
         * 旋转数组可以看成是由左右两个递增数组组成
         * 通过将right指向的元素与middle指向的元素比较
         * 如果小于，则说明middle处于左边的递增数组，left = middle + 1，搜寻范围右移
         * 如果大于，则说明middle处于右边的递增数组，right = middle，搜寻范围左移
         * 如果等于，此时并不能判断到底处于左边还是右边，可以看成是顺序性丢失了，此时right -- ，二分查找退化为普通顺序遍历
         * 二分查找介绍 https://www.cnblogs.com/iwiniwin/p/10793650.html
         */
        int minNumberInRotateArray2(vector<int> rotateArray) {
            if(rotateArray.size() == 0) return 0;
            int left = 0;
            int right = rotateArray.size() - 1;
            while (left < right) {
                int middle = (left + right) / 2;
                if(rotateArray[middle] > rotateArray[right]) {
                    left = middle + 1;
                } else if(rotateArray[middle] < rotateArray[right]) {
                    right = middle;
                } else {
                    right --;
                }
            }
            return rotateArray[left];
        }

        void Test() {
            vector<int> rotateArray = {3, 4, 5, 1, 2};
            rotateArray = {3, 100, 200, 3};
            rotateArray = {2};
            rotateArray = {2, 2, 2};
            rotateArray = {2, 3, 1, 2};
//            print(minNumberInRotateArray(rotateArray));
            print(minNumberInRotateArray2(rotateArray));

        }
    };
}


#endif //ALGORITHM_CPP_MIN_NUMBER_IN_ROTATE_ARRAY_H
