// step 1: clarify
// 
// step 2: solution
//
// for loop the linked list, set the next pointer of current node to the current head and set it to be the new head.
//
// step 3: coding
//
// step 4: testing
//
// 1. nullptr
// 2. only one element
// 3. only two elements

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
