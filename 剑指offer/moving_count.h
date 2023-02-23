/*
题目名称：
机器人的运动范围

题目描述：
地上有一个m行和n列的方格。
一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
请问该机器人能够达到多少个格子？

代码结构：
class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {

    }
};

想法：
递归走格子，数量累加
怎么避免走重复的，用一个二维数组记录？
是遍历二维数组最后拿到结果 还是 在递归中就准确累加出来呢
*/

#ifndef ALGORITHM_CPP_MOVING_COUNT_H
#define ALGORITHM_CPP_MOVING_COUNT_H
#include "../common.h"


namespace MovingCount {
    class Solution {
    public:
        /*
         * 解法
         * 基本思路：
         * 利用递归，从0，0点，开始向上下左右开始搜索
         * 利用record数组记录搜索过的节点，置为true。
         * 注意，这里在回溯的时候是不用将标记还原的
         */
        int movingCount(int threshold, int rows, int cols) {
            vector<vector<bool>> record(rows, vector<bool>(cols, false));
            return move(threshold, rows, cols, 0, 0, record);
        }

        int move(int threshold, int rows, int cols, int row, int col, vector<vector<bool>>& record) {
            if(row < 0 || row >= rows || col < 0 || col >= cols) return 0;
            if(!record[row][col] && sumDigit(row) + sumDigit(col) <= threshold) {
                record[row][col] = true;
                int count = 1;
                count += move(threshold, rows, cols, row + 1, col, record);
                count += move(threshold, rows, cols, row - 1, col, record);
                count += move(threshold, rows, cols, row, col + 1, record);
                count += move(threshold, rows, cols, row, col - 1, record);
                return count;
            }
            return 0;
        }

        int sumDigit(int num) {
            int sum = 0;
            while (num > 0) {
                sum += (num % 10);
                num /= 10;
            }
            return sum;
        }

        void Test() {
            int threshold = 1;
            threshold = 0;
            threshold = 10;
            int rows = 2;
            rows = 1;
            int cols = 3;
            cols = 100;
            print(movingCount(threshold, rows, cols));
        }
    };
}


#endif //ALGORITHM_CPP_MOVING_COUNT_H
