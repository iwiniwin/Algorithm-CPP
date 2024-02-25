/*
题目名称：
数字在排序数组中出现的次数

题目描述：
统计一个数字在排序数组中出现的次数。

代码结构：
class Solution
{
    public int GetNumberOfK(int[] data, int k)
    {
        // write code here
    }
}
*/

#ifndef ALGORITHM_CPP_GET_NUMBER_OF_K_H
#define ALGORITHM_CPP_GET_NUMBER_OF_K_H
#include "../common.h"
namespace GetNumberOfK {
    class Solution {
    public:
        int GetNumberOfK(vector<int> data, int k) {
            return Find(data, k + 0.5) - Find(data, k - 0.5);
        }

        int Find(vector<int> data, double k) {
            int left = 0;
            int right = data.size() - 1;
            bool bIncrease = data[left] < data[right];
            while(left <= right) {
                int middle = (left + right) / 2;
                if(data[middle] < k) {
                    if(bIncrease)
                    {
                        left = middle + 1;
                    }
                    else
                    {
                        right = middle - 1;
                    }
                }
                else if(data[middle] > k) {
                    if(bIncrease)
                    {
                        right = middle - 1;
                    }
                    else
                    {
                        left = middle + 1;
                    }
                }
                else
                {
                    return middle;
                }
            }
            return bIncrease ? left : -left;
        }

        void Test() {
//            vector<int> data = {0, 1, 1, 3, 3, 3, 4, 4, 8};
//            vector<int> data = {1, 2, 3, 3, 4};
            vector<int> data = {8, 4, 4, 3, 3, 3, 1, 1, 0};
            print(GetNumberOfK(data, 3));
        }
    };
}

#endif //ALGORITHM_CPP_GET_NUMBER_OF_K_H
