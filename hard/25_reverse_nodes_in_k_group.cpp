// step 1: clarify
//
// step 2: solutions
//
// 1. reverse the linked list
// 2, reverse the linked list in k groups
//
// step 3: coding
//
// step 4: testing

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // find k as a group
        int id = 0;
        ListNode* node = head;
        for (id = 0; id < k; ++id) {
            if (node == nullptr)
                break;
            node = node->next;
        }
        // the remaining do not has k elements
        if (id < k)
            return head;
        ListNode* sub_head = reverseKGroup(node, k);
        // reverse the k elements
        node = head;
        ListNode* prev = sub_head;
        for (id = 0; id < k; ++id) {
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};
