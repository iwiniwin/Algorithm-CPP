/*
题目名称：
从尾到头打印链表

题目描述：
输入一个链表的头节点，按链表从尾到头的顺序返回每个节点的值（用数组返回）。

代码结构：
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {

    }
};

想法：
递归
利用栈
正常遍历 vector每次往前插入
*/

#ifndef ALGORITHM_CPP_PRINT_LIST_FROM_TAIL_TO_HEAD_H
#define ALGORITHM_CPP_PRINT_LIST_FROM_TAIL_TO_HEAD_H

#include <iostream>
#include <vector>

using namespace std;

namespace PrintListFromTailToHead {
    struct ListNode {
        int val;
        struct ListNode *next;

        ListNode(int x) :
                val(x), next(NULL) {
        }
    };

    class Solution {
    public:
        vector<int> PrintListFromTailToHead(ListNode *head) {

        }

        void Test() {
            std::cout << "test" << endl;
        }
    };
}


#endif //ALGORITHM_CPP_PRINT_LIST_FROM_TAIL_TO_HEAD_H
