//
// 剑指offer
//

#ifndef ALGORITHM_CPP_CODING_INTERVIEWS_PROGRAM_H
#define ALGORITHM_CPP_CODING_INTERVIEWS_PROGRAM_H

#include "剑指offer/find.h"
#include "剑指offer/duplicate.h"
#include "剑指offer/replace_space.h"
#include "剑指offer/print_list_from_tail_to_head.h"
#include "剑指offer/re_construct_binary_tree.h"

namespace Algorithm {

    class CodingInterviewsProgram {
    public:
        static void Test() {
//            Find::Solution().Test();
//            Duplicate::Solution().Test();
//            ReplaceSpace::Solution().Test();
//            PrintListFromTailToHead::Solution().Test();
            ReConstructBinaryTree::Solution().Test();
        }
    };

} // Algorithm

#endif //ALGORITHM_CPP_CODING_INTERVIEWS_PROGRAM_H
