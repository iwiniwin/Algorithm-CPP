/*
题目名称：
序列化二叉树

题目描述：
请实现两个函数，分别用来序列化和反序列化二叉树

二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，
从而使得内存中建立起来的二叉树可以持久保存。
序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，
序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#）

二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。

代码结构：
class Solution {
public:
    char* Serialize(TreeNode *root) {

    }
    TreeNode* Deserialize(char *str) {

    }
};

想法：
层次遍历
先序遍历，Deserialize怎么确定后面的字符串哪些是left，哪些是right。左子树遍历结束后返回的
*/

#ifndef ALGORITHM_CPP_SERIALIZE_BINARY_TREE_H
#define ALGORITHM_CPP_SERIALIZE_BINARY_TREE_H

#include "../common.h"
#include <queue>

namespace SerializeBinaryTree {
    class Solution {
    public:
        /*
         * 解法1，层次遍历
         * 基本思路：
         * 序列化，利用一个辅助队列，遍历树，队列中依次保存二叉树每一层的所有节点
         * 空节点使用'#'表示，节点之间通过'!'分隔
         * 反序列化，与序列化相同的遍历方式构造树
         */
        char *Serialize(TreeNode *root) {
            if (root == nullptr) return "";
            string s = "";
            queue<TreeNode *> nodes;
            nodes.push(root);
            while (!nodes.empty()) {
                TreeNode *node = nodes.front();
                nodes.pop();
                if (node != nullptr) {
                    s += to_string(node->val) + "!";
                    nodes.push(node->left);
                    nodes.push(node->right);
                } else {
                    s += "#!";
                }
            }
            char *data = new char[s.length() + 1];
            strcpy(data, s.data());
            data[s.length()] = '\0';
            return data;
        }

        TreeNode *Deserialize(char *str) {
            string s = str;
            if (s.length() == 0) return nullptr;
            int start = 0, end = 0;
            end = s.find("!", start);
            string val = s.substr(start, end - start);
            start = end + 1;
            TreeNode *root = new TreeNode(stoi(val));
            queue<TreeNode *> nodes;
            nodes.push(root);
            while (!nodes.empty()) {
                TreeNode *node = nodes.front();
                nodes.pop();
                end = s.find("!", start);
                val = s.substr(start, end - start);
                start = end + 1;
                if(val != "#") {
                    node->left = new TreeNode(stoi(val));
                    nodes.push(node->left);
                }
                end = s.find("!", start);
                val = s.substr(start, end - start);
                start = end + 1;
                if(val != "#") {
                    node->right = new TreeNode(stoi(val));
                    nodes.push(node->right);
                }
            }
            return root;
        }


        /*
         * 解法2，先序遍历
         * 基本思路：
         * 先序遍历，递归，序列化字符串
         * 利用引用类型，记录start值，按照先序遍历规则反序列化字符串
         */
        char* Serialize2(TreeNode *root) {
            if(root == nullptr) return "#!";
            string s = to_string(root->val) + "!";
            s += Serialize2(root->left);
            s += Serialize2(root->right);
            char *data = new char[s.length() + 1];
            strcpy(data, s.data());
            data[s.length()] = '\0';
            return data;
        }

        TreeNode* Deserialize2(char *str) {
            if(str == nullptr) return nullptr;
            string s = str;
            int start = 0;
            return Deserialize2Impl(s, start);
        }

        TreeNode* Deserialize2Impl(string s, int &start) {
            int end = s.find("!", start);
            string val = s.substr(start, end - start);
            start = end + 1;
            if(val == "#") return nullptr;
            TreeNode *root = new TreeNode(stoi(val));
            root->left = Deserialize2Impl(s, start);
            root->right = Deserialize2Impl(s, start);
            return root;
        }

        void Test() {
            TreeNode *root = new TreeNode(1);
            root->left = new TreeNode(2);
            root->right = new TreeNode(368);
            root->right->left = new TreeNode(6);
            root->right->right = new TreeNode(75);

//            char *str = Serialize(root);
//            print(str);
//            TreeNode *node = Deserialize(str);
//            print(node);

            char *str = Serialize2(root);
            print(str);
            TreeNode *node = Deserialize2(str);
            print(node);
        }
    };
}


#endif //ALGORITHM_CPP_SERIALIZE_BINARY_TREE_H
