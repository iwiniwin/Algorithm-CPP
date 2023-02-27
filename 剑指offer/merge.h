/*
题目名称：
合并两个排序的链表

题目描述：
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

代码结构：
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {

    }
};
*/

#ifndef ALGORITHM_CPP_MERGE_H
#define ALGORITHM_CPP_MERGE_H
#include "../common.h"

namespace Merge {
    class Solution {
    public:
        /*
         * 解法1
         * 基本思路：
         * 同时遍历两个链表，比较两个链表的首结点，优先合并其中较小的节点
         * 当两个链表长度不同时，最后再合并两个链表中较长链表的剩余节点
         */
        ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
            ListNode * node = new ListNode(0), *p = node;
            while(pHead1 != nullptr && pHead2 != nullptr) {
                if(pHead1->val <= pHead2->val) {
                    p->next = pHead1;
                    pHead1 = pHead1->next;
                } else {
                    p->next = pHead2;
                    pHead2 = pHead2->next;
                }
                p = p->next;
            }
            if(pHead1 != nullptr) {
                p->next = pHead1;
            }
            if(pHead2 != nullptr) {
                p->next = pHead2;
            }
            return node->next;
        }

        /*
         * 解法2，递归
         * 基本思路：
         * 比较两个链表中最小的节点，选择最小节点作为head，继续递归剩下的节点
         * 首先算法合并两个链表头节点中较小的节点，即将较小的节点作为新链表的头结点
         * 然后通过递归寻找新链表头结点的下一个节点，过程如下
         * 如果链表1的头结点较小，则链表1向下走一步，链表1指向下一个节点，找到链表1与链表2中较小的头结点
         * 如果链表2的头结点较小，则链表2向下走一步，链表2指向下一个节点，找到链表1与链表2中较小的头结点
         */
        ListNode* Merge2(ListNode* pHead1, ListNode* pHead2) {
            if(pHead1 == nullptr && pHead2 == nullptr) return nullptr;
            if(pHead1 == nullptr) return pHead2;
            if(pHead2 == nullptr) return pHead1;
            if(pHead1->val <= pHead2->val) {
                pHead1->next = Merge2(pHead1->next, pHead2);
                return pHead1;
            } else {
                pHead2->next = Merge2(pHead1, pHead2->next);
                return pHead2;
            }
        }

        void Test() {
            ListNode *pHead1 = new ListNode(1);
            pHead1->next = new ListNode(3);
            pHead1->next->next = new ListNode(5);

            ListNode *pHead2 = new ListNode(2);
            pHead2->next = new ListNode(4);
//            pHead2->next->next = new ListNode(6);

//            print(Merge(pHead1, pHead2));
            print(Merge2(pHead1, pHead2));
        }
    };
}


#endif //ALGORITHM_CPP_MERGE_H
