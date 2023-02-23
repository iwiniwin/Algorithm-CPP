/*
题目名称：
矩阵中的路径

题目描述：
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，
但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
路径不能再次进入该格子。

代码结构：
class Solution {
public:
    bool hasPath(vector<vector<char> >& matrix, string word) {
        // write code here
    }
};

想法：
递归，遍历substring，在矩阵中记录是否走过
*/

#ifndef ALGORITHM_CPP_HAS_PATH_H
#define ALGORITHM_CPP_HAS_PATH_H

#include "../common.h"

namespace HasPath {
    class Solution {
    public:
        /*
         * 解法
         * 基本思路：
         * 分别以矩阵的每个元素为起点，判断路径是否存在
         * 从起点开始按上下左右的顺序搜索，已经经过的元素标记为true
         * 如果此路不通，则回溯到上一层，并还原标记位
         */
        bool hasPath(vector<vector<char> > &matrix, string word) {
            if (matrix.size() == 0 || matrix[0].size() == 0) return false;
            vector<vector<bool>> record(matrix.size(), vector<bool>(matrix.size(), false));
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    if (hasPath(matrix, i, j, record, word, 0)) {
                        return true;
                    }
                }
            }
            return false;
        }

        bool
        hasPath(vector<vector<char>> &matrix, int row, int col, vector<vector<bool>> &record, string word, int offset) {
            if (offset >= word.length()) return true;
            if (row >= matrix.size() || col >= matrix[row].size()) return false;
            if (matrix[row][col] == word[offset] && !record[row][col]) {
                record[row][col] = true;
                bool ret = hasPath(matrix, row + 1, col, record, word, offset + 1) ||
                           hasPath(matrix, row - 1, col, record, word, offset + 1) ||
                           hasPath(matrix, row, col + 1, record, word, offset + 1) ||
                           hasPath(matrix, row, col - 1, record, word, offset + 1);
                record[row][col] = false;
                return ret;
            }
            return false;
        }

        void Test() {
            vector<vector<char>> matrix = {
                    {'a', 'b', 'c', 'e'},
                    {'s', 'f', 'c', 's'},
                    {'a', 'd', 'e', 'e'}
            };
//            matrix = {};
            string word = "abcced";
//            word = "abcb";
            print(hasPath(matrix, word));
        }
    };
}


#endif //ALGORITHM_CPP_HAS_PATH_H
