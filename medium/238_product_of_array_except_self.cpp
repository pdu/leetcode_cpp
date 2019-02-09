// step 1: clarify
//
// the product cannot overflow
//
// step 2: solution
//
// calculate the sum of the whole array, and divide itself to get the result
// time complexity: O(n)
// space complexity: O(1)
//
// if cannot use divide, we can init the result array as 1,
// 1. for loop from left to right, ret[i] *= ret[i - 1] * array[i - 1]
// 2. for loop from right to left, ret[i] *= ret[i + 1] * array[i + 1]
// time complexity: O(n)
// space complexity: O(1)
//
// step 3: coding
//
// step 4: testing

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 1);
        for (int i = 1; i < n; ++i)
            ret[i] = ret[i - 1] * nums[i - 1];
        int p = 1;
        for (int i = n - 2; i >= 0; --i) {
            p *= nums[i + 1];
            ret[i] *= p;
        }
        return ret;
    }
};
