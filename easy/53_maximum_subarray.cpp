// step 1: clarify
//
// 1. find the contiguous subarray, at least one element
// 2. have negative number
//
// step 2: solutions
//
// the naive way is to enumerate all the ranges and calculate the sum
// time complexiy: O(n^3)
// space complexity: O(1)
//
// optimise the part of calculating the sum, use an array to store all the sums in the range of [0, i], 0 <= i < n
// time complexity: O(n^2)
// space complexity: O(n)
//
// based on the above solution, we can define the state: f[i] --> the maximum sum ending with i-th element
// f[i] = nums[i] + max(f[i-1], 0), starting with f[0] = nums[0]
// maximum_sum = max(f[i]), 0 <= i < n
// time complexity: O(n)
// space complexity: O(1), because we only use the the f[i-1], we can just use one variable is enough

#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = INT_MIN;
        int sum = 0;
        for (auto n: nums) {
            sum += n;
            ret = max(ret, sum);
            if (sum < 0)
                sum = 0;
        }
        return ret;
    }
};
