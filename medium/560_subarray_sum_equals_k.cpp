// hash

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums(nums.size());
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            sums[i] = sums[i - 1] + nums[i];
        int ret = 0;
        unordered_map<int, int> hash;
        for (int i = nums.size() - 1; i >= 0; --i) {
            auto it = hash.find(sums[i]);
            if (it == hash.end())
                hash[sums[i]] = 1;
            else
                it->second++;
            int target = k + (i >= 1 ? sums[i - 1] : 0);
            it = hash.find(target);
            if (it != hash.end())
                ret += it->second;
        }
        return ret;
    }
};
