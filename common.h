//
// Created by IWIN on 2023/2/22.
//

#ifndef ALGORITHM_CPP_COMMON_H
#define ALGORITHM_CPP_COMMON_H
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

void print(vector<int> list) {
    for (auto it = list.begin(); it != list.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << endl;
}

void print(int val) {
    std::cout << val << endl;
}

void print(double val) {
    std::cout << val << endl;
}

void print(string s) {
    std::cout << s << endl;
}

void print(TreeNode *head) {
    queue<TreeNode*> nodes;
    nodes.push(head);
    while(!nodes.empty()) {
        TreeNode *node = nodes.front();
        nodes.pop();
        if(node != NULL) {
            std::cout << node->val << " ";
            nodes.push(node->left);
            nodes.push(node->right);
        } else {
            std::cout << "# ";
        }
    }
    std::cout << endl;
}

void print(ListNode *head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << endl;
}


void print(RandomListNode *head) {
    RandomListNode *p = head;
    while (p != nullptr) {
        std::cout << p->label << " ";
        p = p->next;
    }
    p = head;
    while (p != nullptr) {
        if(p->random == nullptr) {
            std::cout << "# ";
        } else {
            std::cout << p->random->label << " ";
        }
        p = p->next;
    }
    std::cout << endl;
}

#endif //ALGORITHM_CPP_CONSOLE_H
