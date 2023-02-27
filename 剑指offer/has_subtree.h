/*
题目名称：
树的子结构

题目描述：
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

代码结构：
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {

    }
};
*/

#ifndef ALGORITHM_CPP_HAS_SUBTREE_H
#define ALGORITHM_CPP_HAS_SUBTREE_H

#include "../common.h"

namespace HasSubtree {
    class Solution {
    public:
        /*
         * 解法，递归
         * 基本思路：
         * 如果两颗树的根节点相同，则接着判断两颗树的左右子树是否是子树关系
         * 如果也是的话直接返回true
         * 如果不是的话，就什么也不做，因为目前仍不能判断B是不是A的子树
         * 接着判断B是否是A的左子树的子树，如果是的直接返回true
         * 接着判断B是否是A的右子树的子树，如果是的直接返回true
         */
        bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
            if (pRoot1 == nullptr || pRoot2 == nullptr) return false;
            if (pRoot1->val == pRoot2->val) {
                if((pRoot2->left == nullptr || HasSubtree(pRoot1->left, pRoot2->left)) &&
                        (pRoot2->right == nullptr || HasSubtree(pRoot1->right, pRoot2->right))) {
                    return true;
                }
            }
            return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
        }

        void Test() {
            TreeNode *pRoot1 = new TreeNode(8);
            pRoot1->left = new TreeNode(8);
            pRoot1->right = new TreeNode(7);
            pRoot1->left->left = new TreeNode(9);
            pRoot1->left->right = new TreeNode(2);
            pRoot1->left->right->left = new TreeNode(4);
            pRoot1->left->right->right = new TreeNode(7);

            TreeNode *pRoot2 = new TreeNode(8);
            pRoot2->left = new TreeNode(9);
            pRoot2->right = new TreeNode(2);
//            pRoot2->right->left = new TreeNode(4);
//            pRoot2->right->left = new TreeNode(7);

            print(HasSubtree(pRoot1, pRoot2));
        }
    };
}


#endif //ALGORITHM_CPP_HAS_SUBTREE_H
