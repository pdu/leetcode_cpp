// dynamic programming
//
// state: f[n], the maximum money after robbering index n houses
// transfer: f[n] = max(value[n] + f[n-2], f[n-1])
// init: f[0] = value[0], f[1] = max(value[0], value[1]);

#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> f(3);
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            f[i%3] = max(nums[i] + f[(i-2)%3], f[(i-1)%3]);
        }
        return f[(nums.size()-1)%3];
    }
};
