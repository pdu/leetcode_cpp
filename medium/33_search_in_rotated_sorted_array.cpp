// step 1: clarify
//
// no duplicate elements
//
// step 2: solution
//
// 1. first check it's sorted or rotated sorted:
//  head > tail: rotated
//  else: sorted
// 2. if sorted, normal binary search
// 3. if rotated, check the mid value in two phrase:
//       -
//      -
//     -
//    -
//         -
//        -
//    mid >= head: first part
//      target > mid: tail
//      target < mid and target > head: head
//      target < head: tail
//    else: second part
//      target < mid: head
//      target > mid and target < tail: tail
//      target > tail: head
//
// step 3: coding
//
// step 4: testing

#include <vector>

using namespace std;

class Solution {
public:
    int search(const vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target)
                return mid;
            // sorted array
            if (nums[left] <= nums[right]) {
                if (nums[mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
                continue;
            }
            // rotated sorted array
            if (nums[mid] >= nums[left]) {
                if (nums[mid] < target)
                    left = mid + 1;
                else if (target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (nums[mid] > target)
                    right = mid - 1;
                else if (target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};
