struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n)
            return head;
        ListNode stub(0);
        stub.next = head;

        ListNode* curr = &stub;
        ListNode* prev = nullptr;
        for (int i = 0; i < m; ++i) {
            prev = curr;
            curr = curr->next;
        }

        ListNode* prev2 = nullptr;
        for (int i = m; i <= n; ++i) {
            ListNode* next = curr->next;
            curr->next = prev2;
            prev2 = curr;
            curr = next;
        }

        prev->next->next = curr;
        prev->next = prev2;

        return stub.next;
    }
};
