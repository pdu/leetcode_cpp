// step 1: clarify
//
// step 2: solutions
//
// straightforward solution is to store all the nodes in hash table while doing the for loop
// then check whether the node contained in the hash table or not
// time complexity: O(n)
// space complexity: O(n)
//
// another very tricky solution which is very difficulty to think out during the interview is:
// 1. you have slow pointer and fast pointer
// 2. each time the slow pointer moves 1 step forward while the fast pointer moves 2 steps forward
// 3. if the slow pointer meets the fast pointer, the linked list has cycle
// time complexity: O(n)
// space complexity: O(1)
//
// proof:
// ----a----O------
//          -     -
//          -     b
//          ---c--X
//
// if the linked list has cycle at point O and the slow pointer meets the fast pointer at point X
// a, b and c are the distances between the points
//
// after t times the slow meets the fast:
// slow pointer, t = a + b + p * (b + c), it goes p rounds
// fast pointer, 2 * t = a + b + q * (b + c), it goes q rounds
// so t = (b + c) * (q - p)
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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
