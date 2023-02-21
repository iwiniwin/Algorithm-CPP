/*
题目名称：
二维数组中的查找

题目描述：
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

代码结构：
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {

    }
};

想法：
先从左到右遍历，如果元素没有target大，就往右找，如果比target小，就不知道应该怎么找了
如果下面的元素都比target小，不就可以向下找了吗
对，可以从左下角开始找，从左到右递增，从下到上递减
1  2  3  4
2  3  4  5
 */

#ifndef ALGORITHM_CPP_FIND_H
#define ALGORITHM_CPP_FIND_H

#include <iostream>
#include <vector>

using namespace std;

namespace Find {

    class Solution {
    public:
        /*!
         * 解法1
         * 基本思路：
         * 根据数组从左到右递增，从上到下递增的特性可以发现，
         * 当从数组的左下角开始判断时，从左到右是递增的，从下到上是递减的
         * 此时，如果target比当前元素大，就向右找，如果比当前元素小，就向上找
         * 从数组的右上角开始也是类似的
         */
        bool Find(int target, vector<vector<int> > array) {
            int row = array.size();
            if(row == 0) return false;
            int col = array[0].size();
            if(col == 0) return false;
            int i = row - 1;
            int j = 0;
            while (i >= 0 && j < col) {
                if (target < array[i][j]) {
                    i--;
                } else if (target > array[i][j]) {
                    j++;
                } else {
                    return true;
                }
            }
            return false;
        }

        void Test() {
            vector<vector<int>> array = {
                    {1, 2, 8, 9},
                    {2, 4, 9, 12},
                    {4, 7, 10, 13},
                    {6, 8, 11, 15}
            };
//            vector<vector<int>> array = {
//                    {2}
//            };
            int target = 7;
//            int target = 1;
            std::cout << Find(target, array) << endl;
        }
    };

} // Find

#endif //ALGORITHM_CPP_FIND_H
