/*
题目名称：
链表中环的入口结点

题目描述：
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

代码结构：
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {

    }
};

想法：
快慢指针，如果有环，快的一定会追上慢的，相遇点是在环内。那怎么找到入口节点呢
通过相遇点计算环的长度，再从起点走一遍的长度，两者差值就是入口节点
如果纯环，只有环的时候
环的长度的计算，要考虑自循环，2节点循环，3节点循环
*/

#ifndef ALGORITHM_CPP_ENTRY_NODE_OF_LOOP_H
#define ALGORITHM_CPP_ENTRY_NODE_OF_LOOP_H

#include "../common.h"

namespace EntryNodeOfLoop {
    class Solution {
    public:
        /*
         * 解法1，断链法基本思路：
         * 首先判断链表是否包含环。
         * 定义快慢指针，快指针走两步，慢指针走一步，如果有环，快慢指针一定会相遇（快指针会追上慢指针）。
         * 如果一个链表包含环，则该链表可以无限遍历下去。
         * 此时每遍历到一个节点，便将该节点的前驱节点的next置为空（断链，断开前驱节点与当前节点的连接）
         * 当某个节点的next为空时，说明此前已经被破坏过，该节点即为环的入口节点
         * 注意，这种解法会破坏原链表的结构
         */
        ListNode *EntryNodeOfLoop(ListNode *pHead) {
            if (pHead == nullptr) return nullptr;
            ListNode *p = pHead->next, *q = pHead;
            while (p != nullptr && p->next != nullptr && q != nullptr && p != q) {
                p = p->next->next;
                q = q->next;
            }
            if (p != q) return nullptr;
            p = pHead;
            q = pHead;
            while (p != nullptr) {
                q = p;
                p = p->next;
                q->next = nullptr;
            }
            return q;
        }

        /*
         * 解法2
         * 基本思路：
         * 定义一个快指针，一个慢指针，都指向链表的头部
         * 如果链表包含环，假设环长度为n。
         * 让快指针先走n步，然后再让快慢指针一起走（都是每次走一步），则它们一定相遇于环的入口节点
         * 问题在于如何计算环的长度
         * 上面在判断是否包含环时，会找到使两个指针相遇的节点，这个相遇点一定在环内。
         * 从这个相遇点继续遍历，再次回到相遇点时经过的长度就是环长
         */
        ListNode *EntryNodeOfLoop2(ListNode *pHead) {
            if (pHead == nullptr) return nullptr;
            ListNode *p = pHead->next, *q = pHead;
            while (p != nullptr && p->next != nullptr && q != nullptr && p != q) {
                p = p->next->next;
                q = q->next;
            }
            if (p != q) return nullptr;
            int len = 0;
            p = p->next;
            while (p != q) {
                p = p->next;
                len++;
            }
            p = pHead->next;
            q = pHead;
            while (p != q) {
                if (len-- <= 0) {
                    q = q->next;
                }
                p = p->next;
            }
            return p;
        }

        /*
         * 解法3
         * 基本思路：
         * 首先判断链表是否包含换环，利用快慢指针找到相遇点
         * 假设链表起点到环的入口点距离为a，环的入口点到相遇点距离为b（顺时针），相遇点到环的入口点距离为c（顺时针
         * 定义快指针走两步，慢指针走一步，所以快指针走过的路程是慢指针的2倍
         * 则快指针走过的距离为 x = a + n（b + c）+ b
         * 慢指针走过的距离为 y = a + b + m (b + c)
         * 由 x = 2y 得 a + n（b + c）+ b = 2 * (a + b + m (b + c))
         * 进一步推导得到 a = (n - 2m - 1) *（b + c）+ c
         * 表示从链表起点到环入口点的距离 = (n - 2m - 1)环长 + 相遇点到环入口点的长度(c)
         * 因此两个指针分别从链表起点和相遇点开始移动，一定会在环入口点相遇
         * 注意由于是根据公式推导得出的结论，所以快指针和慢指针走过的距离计算一定要准确，保证是2倍的关系
         */
        ListNode *EntryNodeOfLoop3(ListNode *pHead) {
            if (pHead == nullptr) return nullptr;
            ListNode *p = pHead, *q = pHead;
            bool hasRing = false;
            while (p != nullptr && p->next != nullptr && q != nullptr) {
                p = p->next->next;
                q = q->next;
                if (p == q) {
                    hasRing = true;
                    break;
                };
            }
            if (!hasRing) return nullptr;
            p = pHead;
            while (p != q) {
                p = p->next;
                q = q->next;
            }
            return p;
        }

        // WA代码
        /*
        ListNode *EntryNodeOfLoop(ListNode *pHead) {
            if (pHead == nullptr || pHead->next == nullptr) return nullptr;
            ListNode *p = pHead, *q = pHead;
            while (p != nullptr && p->next != nullptr && q != nullptr) {
                p = p->next->next;
                q = q->next;
                if (p == q) break;
            }
            if (p != q) return nullptr;
            int total = 0, count = 0, ring = 0;
            p = pHead;
            while (true) {  // 错误点 这里错误的关键在于计算total长度有误 当相遇点就是入口节点时不对 比如{1,2},{3,4,5} 和 {1,2,3},{4,5,6}
                p = p->next;
                if (p == pHead) {
                    return pHead;
                }
                if (p == q) {
                    if (count > 0) {
                        break;
                    }
                    count++;
                }
                total++;
            }
            p = q->next;
            if(p != q) {
                ring ++;
                while (p != q) {
                    p = p->next;
                    ring++;
                }
            }
            int len = total - ring;
            p = pHead;
            while (len-- > 0) {
                p = p->next;
            }
            return p;
        }
        */

        void Test() {
            ListNode *pHead = new ListNode(1);
            pHead->next = new ListNode(2);
            pHead->next->next = new ListNode(3);
//            pHead->next->next = pHead->next;
            pHead->next->next->next = new ListNode(4);
            pHead->next->next->next->next = new ListNode(5);
//            pHead->next->next->next->next->next = new ListNode(6);
//            pHead->next->next->next->next->next->next = pHead->next->next->next;
//            pHead->next->next->next->next->next = pHead->next->next;
//            pHead->next->next->next->next->next = pHead;
//            pHead->next->next->next->next->next = pHead->next->next->next->next;
            pHead->next->next->next->next->next = pHead->next->next->next;
            
//            pHead = new ListNode(1);
//            pHead->next = pHead;
//            pHead->next = new ListNode(2);
//            pHead->next->next = pHead;

//            ListNode *result = EntryNodeOfLoop(pHead);
//            ListNode *result = EntryNodeOfLoop2(pHead);
            ListNode *result = EntryNodeOfLoop3(pHead);
            print(result == nullptr ? "nullptr" : to_string(result->val));
        }
    };
}


#endif //ALGORITHM_CPP_ENTRY_NODE_OF_LOOP_H
