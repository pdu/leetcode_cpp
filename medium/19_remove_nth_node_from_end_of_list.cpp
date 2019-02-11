// use two pointers to find the last n-th element
// use dummy node to make the code simplier

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        while (n--)
            curr = curr->next;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* ptr = &dummy;
        while (curr != nullptr) {
            curr = curr->next;
            ptr = ptr->next;
        }
        ListNode* next = ptr->next;
        ptr->next = next->next;
        delete next;
        return dummy.next;
    }
};
