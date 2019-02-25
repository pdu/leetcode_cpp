#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int steps = 1;
        int max_pos = 0;
        int next_max_pos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int next_pos = i + nums[i];
            if (next_pos >= nums.size() - 1)
                return steps;
            next_max_pos = max(next_max_pos, next_pos);
            if (i == max_pos) {
                max_pos = next_max_pos;
                steps++;
            }
        }
        return -1;
    }
};
