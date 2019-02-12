// step 1: clarify
//
// only int32, cannot overflow
//
// step 2: solutions
//
// 1. transfer to only positive integers
// 2. divisor * 1, * 2, * 4, * 8, ...
// 3. add the sums
//
// HINT: convert all numbers in to negative to avoid overflow
// special treat the result of INT_MIN and INT_MAX to avoid overflow
//
// step 3: coding
//
// step 4: testing
//
// -2147483648 / -1 -> overflow
// -2147483648 / 1 -> -2147483648

#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        if (divisor < 0 && dividend > 0)
            return -divide(-dividend, divisor);
        else if (divisor > 0 && dividend < 0)
            return -divide(dividend, -divisor);
        else if (divisor > 0 && dividend > 0)
            return divide(-dividend, -divisor);
        
        vector<pair<int, int>> bases;
        int val = divisor;
        int count = 1;
        while (true) {
            bases.emplace_back(val, count);
            if (val < dividend - val)
                break;
            val += val;
            count += count;
        }
        int ret = 0;
        for (int i = bases.size() - 1; i >= 0; --i) {
            if (dividend <= bases[i].first) {
                dividend -= bases[i].first;
                ret += bases[i].second;
            }
        }
        return ret;
    }
};
