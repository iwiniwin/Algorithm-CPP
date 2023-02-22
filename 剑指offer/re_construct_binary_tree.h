/*
题目名称：
重建二叉树

题目描述：
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

代码结构：
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {

    }
};

想法：
回忆什么是前序遍历(a b d e c f g)，什么是中序遍历(d b e a f c g)  什么是后序遍历(d e b f g c a)
前序，中序，后序 表示的是根节点的遍历顺序
    a
   b c
 d e f g
*/

#ifndef ALGORITHM_CPP_RE_CONSTRUCT_BINARY_TREE_H
#define ALGORITHM_CPP_RE_CONSTRUCT_BINARY_TREE_H
#include <iostream>
#include <vector>
using namespace std;

namespace ReConstructBinaryTree {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {

        }
        
        void Test() {
            std::cout << "test" << endl;
        }
    };
}


#endif //ALGORITHM_CPP_RE_CONSTRUCT_BINARY_TREE_H
