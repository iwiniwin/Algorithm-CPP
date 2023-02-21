/*
题目名称：
数组中重复的数字

题目描述：
在一个长度为n的数组里的所有数字都在0到n-1的范围内。
数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组[2,3,1,0,2,5,3]，那么对应的输出是2或者3。存在不合法的输入的话输出-1

代码结构：
class Solution
{
    public bool duplicate(int[] numbers, int[] duplication)
    {
        // write code here
    }
}

 想法：
 一开始先想到用map 记录存在的key
 用数组 遍历到在的数字 放到对应的下标里
 能否修改原数组？能的话
*/

#ifndef ALGORITHM_CPP_DUPLICATE_H
#define ALGORITHM_CPP_DUPLICATE_H

#include <iostream>
#include <vector>

using namespace std;

namespace Duplicate {
    class Solution {
    public:
        /*
         * 解法1
         * 基本思路：
         * 利用长度为n的辅助数组记录每个数字的出现次数
         */
        int Duplicate(vector<int> &numbers) {
            vector<int> array(numbers.size());
            for (int i = 0; i < numbers.size(); i++) {
                if (array[numbers[i]] == 1) {
                    return numbers[i];
                } else {
                    array[numbers[i]] = 1;
                }
            }
            return -1;
        }

        /*
         * 解法2
         * 基本思路：
         * 不使用辅助数组，利用原数组保存遍历的信息
         * 当一个数字被访问后，将该数字作为下标位置上的数减去数组的长度（使这个数一定小于0）
         * 之后再遇到相同的数字时，发现对应的下标位置上的数已经小于0，则说明出现了重复元素
         */
        int Duplicate2(vector<int> &numbers) {
            int n = numbers.size();
            for (int i = 0; i < numbers.size(); i++) {
                int ele = numbers[i];
                if (ele < 0) {
                    ele += n;
                }
                if (numbers[ele] < 0) {
                    return ele;
                } else {
                    numbers[ele] -= n;
                }
            }
            return -1;
        }

        /*
         * 解法3
         * 基本思路：
         * 不使用辅助数组
         * 每访问到一个数字，判断这个数字与其下标是否相等，若不相等，则将该数字与以该数字值为下标的位置上的数字进行交换
         * 如果要交换的两个数字相等，则找到了重复数字
         * 可以理解为，让每个数字都在以其值为下标的位置上，如果有重复的数字，那它的位置一定会被重复值占领
         */
        int Duplicate3(vector<int> &numbers) {
            for(int i = 0; i < numbers.size(); i ++) {
                while(i != numbers[i]) {
                    int temp = numbers[i];
                    if(numbers[temp] == temp) {
                        return numbers[i];
                    }
                    numbers[i] = numbers[temp];
                    numbers[temp] = temp;
                }
            }
            return -1;
        }


        void Test() {
            vector<int> numbers = {2, 3, 1, 0, 2, 5, 3};
//            vector<int> numbers = {0};
//            vector<int> numbers = {0, 1};
//            vector<int> numbers = {0, 1, 1};
//            vector<int> numbers = {0, 0};
            std::cout << Duplicate(numbers) << endl;
//            std::cout << Duplicate2(numbers) << endl;
//            std::cout << Duplicate3(numbers) << endl;
        }
    };
}


#endif //ALGORITHM_CPP_DUPLICATE_H
