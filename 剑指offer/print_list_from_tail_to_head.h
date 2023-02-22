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
#include "../common.h"

using namespace std;

namespace PrintListFromTailToHead {

    class Solution {
    public:
        /*
         * 解法1基本思路：
         * while循环从头遍历整个链表，将每个元素插入到List中
         * 因为要求是从尾到头，所以每次插入时利用insert函数不断将元素插入到第一的位置
         */
        vector<int> PrintListFromTailToHead(ListNode *head) {
            vector<int> list;
            while (head != nullptr) {
                list.insert(list.begin(), head->val);
                head = head->next;
            }
            return list;
        }

        /*
         * 解法2
         * 基本思路：
         * 利用递归，不断的查找链表的下一个节点，直到尾结点。然后在回溯过程中将每个节点的值加入到list中
         */
        vector<int> PrintListFromTailToHead2(ListNode *head) {
            vector<int> list;
            PrintListFromTailToHead2Impl(list, head);
            return list;
        }

        void PrintListFromTailToHead2Impl(vector<int>& list, ListNode *head) {
            if (head != nullptr) {
                PrintListFromTailToHead2Impl(list, head->next);
                list.push_back(head->val);
            }
        }

        void Test() {
            ListNode *head = new ListNode(1);
            head->next = new ListNode(2);
            head->next->next = new ListNode(3);

//            vector<int> list = PrintListFromTailToHead(head);
            vector<int> list = PrintListFromTailToHead2(head);
            print(PrintListFromTailToHead2(head));
        }
    };
}


#endif //ALGORITHM_CPP_PRINT_LIST_FROM_TAIL_TO_HEAD_H
