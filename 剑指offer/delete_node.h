/*
题目名称：
删除链表的节点

题目描述：
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点。

1.此题对比原题有改动
2.题目保证链表中节点的值互不相同
3.该题只会输出返回的链表和结果做对比，所以若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点

代码结构：
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        // write code here
    }
};
*/

#ifndef ALGORITHM_CPP_DELETE_NODE_H
#define ALGORITHM_CPP_DELETE_NODE_H
#include "../common.h"

namespace DeleteNode {
    class Solution {
    public:

        ListNode* deleteNode(ListNode* head, int val) {
            // write code here
        }

        void Test() {
            print("test");
        }
    };
}


#endif //ALGORITHM_CPP_DELETE_NODE_H
