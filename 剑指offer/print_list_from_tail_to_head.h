//
// Created by IWIN on 2023/2/21.
//

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
