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
1. 递归 按子树处理。想要截取列表子序列时，可以思考用索引代替，从而避免重新创建列表
2. 想不到还有什么解法了
*/

#ifndef ALGORITHM_CPP_RE_CONSTRUCT_BINARY_TREE_H
#define ALGORITHM_CPP_RE_CONSTRUCT_BINARY_TREE_H

#include "../common.h"

namespace ReConstructBinaryTree {

    class Solution {
    public:
        /*
         * 解法
         * 基本思路：
         * 前序遍历是先根节点再左右节点。所以前序序列的第一个节点一定是根节点
         * 中序遍历是先左节点，再根节点，再右节点。那么在中序序列中找到根节点以后，
         * 根节点左边的元素为左子树中序序列，根节点右边的元素为右子树中序序列
         * 根据左右子树的元素数量，可以再在前序序列中分别找出左右子树的前序序列
         * 再递归重构左右子树即可
         * 举个例子，比如中序序列{4,7,2,1,5,3,8,6}，前序序列{1,2,4,7,3,5,6,8}，根节点是1。
         * 那么A的左子树是由1左边的中序序列{4,7,2}构成的二叉树A1，
         * A的右子树是由1右边的中序序列{5,3,8,6}构成的二叉树A2。
         * 因为A1的中序序列是{4,7,2}，元素个数是3，所以A的前序序列中，
         * 根节点1后面的三个元素即{2,4,7}就是A1的前序序列。
         * 所以A2的前序序列就是{2,4,7}后面的所有元素，即{3,5,6,8}
         * 到现在，我们已经把已知A的前序序列和中序序列求A的问题，转换为已知A1的前序中序序列求A1，已知A2的前序中序序列求A2的问题。
         * 继续递归下去，就可以重建出这颗二叉树了。
         * 前中后序遍历介绍 https://www.cnblogs.com/iwiniwin/p/10793652.html
         */
        TreeNode* ReConstructBinaryTree(vector<int> pre, vector<int> vin) {
            return ReConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
        }

        TreeNode* ReConstructBinaryTree(vector<int> &pre, int pre_left, int pre_right, vector<int> &vin, int vin_left, int vin_right) {
            if(pre_left > pre_right || vin_left > vin_right) return NULL;
            TreeNode *head = new TreeNode(pre[pre_left]);
            for(int i = vin_left; i <= vin_right; i ++) {
                if(vin[i] == head->val) {
                    head->left = ReConstructBinaryTree(pre, pre_left + 1, pre_left + i - vin_left, vin, vin_left, i - 1);
                    head->right = ReConstructBinaryTree(pre, pre_left + i - vin_left + 1, pre_right, vin, i + 1, vin_right);
                }
            }
            return head;
        }

        void Test() {
            vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
//            pre = {1};
//            pre = {1, 2, 3, 4, 5, 6, 7};
            vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
//            vin = {1};
//            vin = {3, 2, 4, 1, 6, 5, 7};
            print(ReConstructBinaryTree(pre, vin));
        }
    };
}


#endif //ALGORITHM_CPP_RE_CONSTRUCT_BINARY_TREE_H
