// step 1: clarify
//
// step 2: solutions
//
// for loop the array to put the non-zero elements to the heading of the array
//
// step 3: coding
//
// step 4: testing

#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int id = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != 0)
                nums[id++] = nums[i];
        for (; id < nums.size(); ++id)
            nums[id] = 0;
    }
};
