// step 1: clarify
//
// step 2: solutions
//
// 1. for loop the linked list to copy the normal linked list
// 2. and also record the old_node -> new_node relationship in the hash table
// 3. for loop again to set the random pointer
//
// step 3: coding
//
// step 4: testing
//
// 1. nullptr
// 2. only one node
// 3. only two nodes

#include <unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode ret(0);
        unordered_map<RandomListNode*, RandomListNode*> hash;
        RandomListNode* ptr_new = &ret;
        for (RandomListNode* ptr_old = head; ptr_old != nullptr; ptr_old = ptr_old->next) {
            RandomListNode* node = new RandomListNode(ptr_old->label);
            ptr_new->next = node;
            ptr_new = node;
            hash[ptr_old] = node;
        }
        for (RandomListNode* ptr_old = head, *ptr_new = ret.next; ptr_old != nullptr; ptr_old = ptr_old->next, ptr_new = ptr_new->next)
            if (ptr_old->random != nullptr)
                ptr_new->random = hash[ptr_old->random];
        return ret.next;
    }
};
