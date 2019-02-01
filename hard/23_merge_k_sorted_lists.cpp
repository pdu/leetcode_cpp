// step 1: clarify
//
// quite straightforward
//
// step 2: solutions
//
// set the pointer to each of the list head, put all the values into the priority_queue
// pop the minimum value one and move the related pointer to the next position
// time complexity: O(n * logk), n is the total number
// space complexity: O(k)
//
// step 3: coding
//
// can put a soldier to make the code easier
//
// step 4: testing

#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int>> ,greater<pair<int, int>>> min_heap;
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i] != nullptr)
                min_heap.emplace(lists[i]->val, i);
        ListNode head(0);
        ListNode* curr = &head;
        while (!min_heap.empty()) {
            auto top = min_heap.top();
            min_heap.pop();
            curr->next = lists[top.second];
            curr = curr->next;
            lists[top.second] = lists[top.second]->next;
            if (lists[top.second] != nullptr)
                min_heap.emplace(lists[top.second]->val, top.second);
        }
        curr->next = nullptr;
        return head.next;
    }
};
