/*
题目名称：
链表中倒数第k个结点

题目描述：
输入一个链表，输出该链表中倒数第k个结点。

代码结构：
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
    }
};

想法：
1. 快慢指针
2. 递归？递归和常规遍历链表没区别
*/

#ifndef ALGORITHM_CPP_FIND_KTH_TO_TAIL_H
#define ALGORITHM_CPP_FIND_KTH_TO_TAIL_H
#include "../common.h"

namespace FindKthToTail {
    class Solution {
    public:
        /*
         * 解法
         * 基本思路：
         * 使用快慢指针，当快指针先走了k步后，慢指针再走
         * 这样相当于快指针一直提前慢指针k个节点
         * 当快指针指向链表末尾时，慢指针指向的就是倒数第k个结点
         */
        ListNode* FindKthToTail(ListNode* pHead, int k) {
            ListNode *result = pHead;
            while(pHead != nullptr) {
                if(k -- <= 0) {
                    result = result->next;
                }
                pHead = pHead->next;
            }
            return k <= 0 ? result : nullptr;
        }

        void Test() {
            ListNode *pHead = new ListNode(1);
            pHead->next = new ListNode(2);
            pHead->next->next = new ListNode(3);
            pHead->next->next->next = new ListNode(4);
            pHead->next->next->next->next = new ListNode(5);

            int k = 2;
            k = 8;
            k = 1;
            k = 0;
            print(FindKthToTail(pHead, k));
        }
    };
}

#endif //ALGORITHM_CPP_FIND_KTH_TO_TAIL_H
