// don't have duplicate elements

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums[0] <= nums.back())
            return nums[0];
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] >= nums[0])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return nums[left];
    }
};
