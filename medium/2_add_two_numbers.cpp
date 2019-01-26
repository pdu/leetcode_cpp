// step 1: clarify
//
// non-empty linkedin list, non-negative integers, no leading zeros
//
// step 2: solution
//
// just normal linked list operations, for loop the list to calculate the sums
// time complexity: O(n)
// space complexity: O(n)
//
// step 3: coding
//
// step 4: testing
//
// 9 + 99 = 108
// 0 + 0 = 0
// 0 + 100 = 100
// 4 + 5 = 9

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        int carry = 0;
        while (carry != 0 || l1 != nullptr || l2 != nullptr) {
            int sum = carry;
            move(&l1, sum);
            move(&l2, sum);
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            } else
                carry = 0;
            ListNode* newNode = new ListNode(sum);
            if (curr != nullptr)
                curr->next = newNode;
            curr = newNode;
            if (head == nullptr)
                head = curr;
        }
        return head;
    }

private:
    void move(ListNode** list, int& sum) {
        if (*list != nullptr) {
            sum += (*list)->val;
            *list = (*list)->next;
        }
    }
};
