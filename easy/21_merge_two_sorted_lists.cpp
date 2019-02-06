// step 1: clarify
//
// step 2: solution
//
// merge sort, use stub node to make the code easier
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* curr = &head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val > l2->val)
                update(&curr, &l2);
            else
                update(&curr, &l1);
        }
        curr->next = l1 == nullptr ? l2 : l1;
        return head.next;
    }

private:
    inline void update(ListNode** curr, ListNode** l) {
        (*curr)->next = *l;
        (*curr) = *l;
        *l = (*l)->next;
    }
};
