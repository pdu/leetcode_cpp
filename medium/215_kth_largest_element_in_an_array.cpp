// solution 1:
// use the min priority queue to store the maximum K elements
// time complexity: O(n * logk)
// space complexity: O(k)
//
// solution 2:
// use quick sort to find the k-th elements
// time complexity: O(n)
// space complexity: O(1)

#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, k);
    }

private:
    int findKthLargest(vector<int>& nums, int lower, int higher, int k) {
        int pivot_id = rand() % (higher - lower + 1) + lower;
        swap(nums[lower], nums[pivot_id]);
        int left = lower + 1;
        int right = higher;
        while (left <= right) {
            if (nums[right] < nums[lower])
                right--;
            else {
                swap(nums[left], nums[right]);
                left++;
            }
        }
        swap(nums[lower], nums[right]);
        int count = right - lower + 1;
        if (k == count)
            return nums[right];
        else if (k < count) 
            return findKthLargest(nums, lower, right - 1, k);
        else
            return findKthLargest(nums, right + 1, higher, k - count);
    }
};
