// moore voting algorithm

#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (count == 0) {
                ret = nums[i];
                count = 1;
            } else if (ret == nums[i])
                count++;
            else
                count--;
        }
        return ret;
    }
};
