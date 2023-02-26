/*
题目名称：
反转链表

题目描述：
输入一个链表，反转链表后，输出新链表的表头。

代码结构：
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {

    }
};

想法：
常规想法，三指针 依次翻转
递归，最终是要返回尾节点（新头节点）的，怎么利用尾节点在递归的过程中反转呢。答案是利用pHead.next.next = phead
*/

#ifndef ALGORITHM_CPP_REVERSE_LIST_H
#define ALGORITHM_CPP_REVERSE_LIST_H
#include "../common.h"

namespace ReverseList {
    class Solution {
    public:
        /*
         * 解法1基本思路：
         * 使用三个指针p， q, t
         * t记录当前节点，q记录上一个节点 p记录下一个节点
         * 首先使用p保存当前节点的下一个节点，然后将当前节点的下一个节点指向q，实现反转
         */
        ListNode* ReverseList(ListNode* pHead) {
            if(pHead == nullptr) return nullptr;
            ListNode *p = pHead, *q = nullptr, *t;
            while (p != nullptr) {
                t = p;
                p = p->next;
                t->next = q;
                q = t;
            }
            return q;
        }

        /*
         * 解法2，递归
         * 基本思路：
         * 通过不断递归，先从链表的尾节点开始反转
         * 然后利用递归的回溯实现按照从尾到头的顺序反转每个节点
         */
        ListNode* ReverseList2(ListNode* pHead) {
            if(pHead == nullptr) return nullptr;
            if(pHead->next == nullptr) return pHead;
            ListNode *node = ReverseList2(pHead->next);
            pHead->next->next = pHead;
            pHead->next = nullptr;
            return node;
        }

        void Test() {
            ListNode *pHead = new ListNode(1);
            pHead->next = new ListNode(2);
            pHead->next->next = new ListNode(3);

//            print(ReverseList(pHead));
            print(ReverseList2(pHead));
        }
    };
}


#endif //ALGORITHM_CPP_REVERSE_LIST_H
