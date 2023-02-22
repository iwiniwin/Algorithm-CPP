//
// Created by IWIN on 2023/2/22.
//

#ifndef ALGORITHM_CPP_COMMON_H
#define ALGORITHM_CPP_COMMON_H
#include <iostream>
#include <queue>
#include <vector>
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

void print(vector<int> list) {
    for (auto it = list.begin(); it != list.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << endl;
}

void print(int val) {
    std::cout << val << endl;
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


#endif //ALGORITHM_CPP_CONSOLE_H
