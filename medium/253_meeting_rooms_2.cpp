// step 1: clarify
//
// step 2: solutions
//
// 1. sort the array by the starting time and ending time
// 2. for loop the array and put the ending time into the priority queue:
//  if the starting time is equal or larger than the top value of priority queue:
//      pop the top, and push the new ending time into the priority queue
//  else:
//      push the new ending time into the priority queue
// time complexity: O(n * logn)
// space complexity: O(n)
//
// step 3: coding
//
// step 4: testing

#include <vector>
#include <queue>

using namespace std;

class Solution {
    int meetingRooms(vector<pair<int, int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (auto& meeting: meetings) {
            if (!min_heap.empty() && meeting.first >= min_heap.top())
                min_heap.pop();
            min_heap.emplace(meeting.second);
        }
        return min_heap.size();
    }
};
