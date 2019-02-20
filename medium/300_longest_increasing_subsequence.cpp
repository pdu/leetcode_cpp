// dynamic programming
// binary search

#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> lis(1, nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > lis.back()) {
                lis.emplace_back(nums[i]);
                continue;
            }
            int left = 0;
            int right = lis.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (lis[mid] >= nums[i])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            lis[left] = nums[i];
        }
        return lis.size();
    }
};
