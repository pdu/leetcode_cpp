struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = 0;
        for (ListNode* curr = head; curr != nullptr; curr = curr->next)
            n++;
        if (n <= 1)
            return true;
        ListNode* back;
        return isPalindrome(head, n, &back);
    }

private:
    bool isPalindrome(ListNode* head, int n, ListNode** next) {
        if (n == 1) {
            *next = head->next;
            return true;
        }
        if (n == 2) {
            *next = head->next->next;
            return head->val == head->next->val;
        }
        ListNode* back = nullptr;
        bool ok = isPalindrome(head->next, n - 2, &back);
        *next = back->next;
        return ok && head->val == back->val;
    }
};
