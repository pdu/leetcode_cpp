// priority_queue: O(n * logk)
// deque: O(n)

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (nums.empty() || k == 0)
            return ret;
        deque<pair<int, int>> list; // first: value second: index
        for (int i = 0; i < k; ++i)
            update(list, nums[i], i, i - k);
        ret.emplace_back(list.front().first);
        for (int i = k; i < nums.size(); ++i) {
            update(list, nums[i], i, i - k);
            ret.emplace_back(list.front().first);
        }
        return ret;
    }

private:
    void update(deque<pair<int, int>>& list, int val, int id, int min_id) {
        while (!list.empty()) {
            if (list.front().second <= min_id)
                list.pop_front();
            else
                break;
        }
        while (!list.empty()) {
            if (list.back().first <= val)
                list.pop_back();
            else
                break;
        }
        list.emplace_back(val, id);
    }
};
