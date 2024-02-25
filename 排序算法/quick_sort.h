/*
算法名称：
快速排序

时间复杂度：O(n*log(2, n))

空间复杂度：O(log(2, n))，递归深度，递归使用的栈空间，以2为底n的对数

最好情况：
O(n*log(2, n)) 每次划分的结果都是左右两个分区大小相等时

最坏情况：
O(n ^ 2) 当选择的分界点一直是最大元素或最小元素时，退化为冒泡排序

稳定性：不稳定，因为将元素移动到分界点两边时，会打乱原本相等元素的顺序

优点：极快

缺点：不稳定

优化：
当待排序列是部分有序时，固定选取枢轴使快排效率低下，要缓解这种情况，可以引入随机选取枢轴
当待排序列长度分割到一定大小后，使用插入排序，因为对于很小和部分有序的数组，直接插入排序效率更好
算法中调用两次QuickSortImpl进行递归，其实第二次可以使用循环代替，改为 left = pivot + 1
*/

#ifndef ALGORITHM_CPP_QUICK_SORT_H
#define ALGORITHM_CPP_QUICK_SORT_H

#include "../common.h"

namespace QuickSort {
    class Solution {
    public:
        void QuickSort(vector<int>& array){
            QuickSortImpl(array, 0, array.size() - 1);
        }

        void QuickSortImpl(vector<int>& array, int left, int right) {
            if(left >= right) return;
            int pivot = Partition(array, left, right);
            QuickSortImpl(array, left, pivot - 1);
            QuickSortImpl(array, pivot + 1, right);
        }

        int Partition(vector<int>& array, int left, int right) {
            int target = array[left];
            while(left < right) {
                while(left < right && array[right] >= target) {
                    -- right;
                }
                if(left < right) {
                    array[left] = array[right];
                }
                while (left < right && array[left] <= target) {
                    ++ left;
                }
                if(left < right) {
                    array[right] = array[left];
                }
            }
            array[left] = target;
            return left;
        }

        void Test() {
            vector<int> array = {1, 3, 4, 0, 9, 8, 0, 1};
            QuickSort(array);
            print(array);
        }
    };
}

#endif //ALGORITHM_CPP_QUICK_SORT_H
