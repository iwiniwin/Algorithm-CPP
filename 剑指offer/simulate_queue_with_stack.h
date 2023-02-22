/*
题目名称：
用两个栈实现队列

题目描述：
用两个栈来实现一个队列，使用n个元素来完成 n 次在队列尾部插入整数(push)和n次在队列头部删除整数(pop)的功能。
队列中的元素为int类型。保证操作合法，即保证pop操作时队列内已有元素。
¡¡
代码结构：
class Solution¡
{
public:
    void push(int node) {

    }

    int pop() {

    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

想法：
队列先进先出 栈先进后出， 两个栈就可以模拟队列了
*/

#ifndef ALGORITHM_CPP_SIMULATE_QUEUE_WITH_STACK_H
#define ALGORITHM_CPP_SIMULATE_QUEUE_WITH_STACK_H
#include "../common.h"

namespace SimulateQueueWithStack {
    class Solution
    {
    public:
        /*
         * 解法
         * 基本思路：
         * 队列的特性是先进先出，而栈的特性是先进后出，可以发现他们的顺序刚好是相反的。
         * 那么自然就想到相反的相反的就是对的顺序了
         * 举个例子，仍然是往栈A中依次插入1，2，3，4，此时它的弹出顺序是4，3，2，1。
         * 若再将这个弹出顺序4，3，2，1，依次插入到栈B中，此时栈B的弹出顺序就是1，2，3，4，
         * 对于最开始插入的1，2，3，4序列刚好满足了先进先出的特性。
         * 栈和队列的介绍 https://www.cnblogs.com/iwiniwin/p/10793651.html
         */

        void push(int node) {
            stack1.push(node);
        }

        int pop() {
            if(stack2.empty()) {
                while (!stack1.empty()) {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            int node = stack2.top();
            stack2.pop();
            return node;
        }

        void Test() {
            push(1);
            push(2);
            print(pop());
            push(3);
            print(pop());
            push(4);
            push(5);
            print(pop());
            print(pop());
            print(pop());
        }

    private:
        stack<int> stack1;
        stack<int> stack2;
    };
}


#endif //ALGORITHM_CPP_SIMULATE_QUEUE_WITH_STACK_H
