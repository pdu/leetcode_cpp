// step 1: clarify
//
// step 2: solutions
//
// 1. use hash table to store the array and check one by one
// time complexity: O(n)
// space complexity: O(n)
//
// 2. swap the elements to the index array equals with the value
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
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            while (nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        int ret = 0;
        for (; ret < nums.size(); ++ret)
            if (nums[ret] != ret + 1)
                break;
        return ret + 1;
    }
};
