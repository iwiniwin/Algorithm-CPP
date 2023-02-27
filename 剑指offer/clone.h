/*
题目名称：
复杂链表的复制

题目描述：
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点）
请对此链表进行深拷贝，并返回拷贝后的头结点。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

代码结构：
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {

    }
};

想法：
遍历复制单链表很容易，复制随机节点时怎么处理，怎么找到随机节点对应的那个引用。复制节点先放在目标节点后面的方法
递归？好像还是没办法复制随机节点
*/

#ifndef ALGORITHM_CPP_CLONE_H
#define ALGORITHM_CPP_CLONE_H

#include "../common.h"

namespace Clone {
    class Solution {
    public:
        /*
         * 解法，三步法
         * 基本思路：
         * 1. 复制链表每个节点，如：复制节点A得到A1，并将A1插入节点A后面
         * 2. 重新遍历链表，为每个复制的节点设置random，如A1.random = A.random.next;
         * 3、将链表拆分成原链表和复制后的链表
         * 第2步是第1步将复制节点插入到原节点后面的原因，这样复制节点的random就是原节点random的下一个节点
         * 可以查看docs/RandomListNode_solution2.png三步法的图示
         */
        RandomListNode *Clone(RandomListNode *pHead) {
            if (pHead == nullptr) return nullptr;
            RandomListNode *p = pHead;
            while (p != nullptr) {
                RandomListNode *node = new RandomListNode(p->label);
                node->next = p->next;
                p->next = node;
                p = node->next;
            }
            p = pHead;
            while (p != nullptr) {
                if (p->random != nullptr) {
                    p->next->random = p->random->next;
                }
                p = p->next->next;
            }
            RandomListNode *head = pHead->next;
            p = pHead;
            while (p != nullptr && p->next != nullptr) {
                RandomListNode *q = p->next;
                p->next = q->next;
                p = q;
            }
            return head;
        }

        void Test() {
            RandomListNode *pHead = new RandomListNode(1);
            pHead->next = new RandomListNode(2);
            pHead->next->next = new RandomListNode(3);
            pHead->next->next->next = new RandomListNode(4);
            pHead->next->next->next->next = new RandomListNode(5);
            pHead->random = pHead->next->next;
            pHead->next->random = pHead->next->next->next->next;
            pHead->next->next->next->random = pHead->next;

            print(Clone(pHead));
        }
    };
}


#endif //ALGORITHM_CPP_CLONE_H
