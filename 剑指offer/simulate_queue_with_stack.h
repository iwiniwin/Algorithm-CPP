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
*/

#ifndef ALGORITHM_CPP_SIMULATE_QUEUE_WITH_STACK_H
#define ALGORITHM_CPP_SIMULATE_QUEUE_WITH_STACK_H
#include "../common.h"

namespace SimulateQueueWithStack {
    class Solution
    {
    public:
        void push(int node) {

        }

        int pop() {

        }

        void Test() {
            print("test");
        }

    private:
        stack<int> stack1;
        stack<int> stack2;
    };
}


#endif //ALGORITHM_CPP_SIMULATE_QUEUE_WITH_STACK_H
