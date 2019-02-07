// step 1: clarify
//
// step 2: solution
//
// the trapping water of each position depends on the minimum boundury of the left side and right side
// area = min(left, right) - height
// so we can for loop from left to right to calculate the left boundury, vise visa from right side
// finally we can get the trapping water of each position and get the final result
//
// step 3: coding
//
// step 4: testing

#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2)
            return 0;
        vector<int> left(n);
        vector<int> right(n);
        left[0] = height[0];
        for (int i = 1; i < n; ++i)
            left[i] = max(left[i - 1], height[i]);
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i)
            right[i] = max(right[i + 1], height[i]);
        int ret = 0;
        for (int i = 1; i < n - 1; ++i)
            ret += min(left[i], right[i]) - height[i];
        return ret;
    }
};
