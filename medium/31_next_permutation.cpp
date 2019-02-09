// step 1: clarify
//
// step 2: solutions
//
// write more examples to find the pattern
//
// step 3: coding
//
// step 4: testing

#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int start = -1;
        int end = -1;
        for (int i = nums.size() - 1; i > start; --i)
            for (int j = i - 1; j > start; --j)
                if (nums[i] > nums[j]) {
                    start = j;
                    end = i;
                    break;
                }
        if (start != -1)
            swap(nums[start], nums[end]);
        sort(nums.begin() + start + 1, nums.end());
    }
};
