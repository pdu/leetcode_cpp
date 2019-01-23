// step 1: clarify
//
// the system can only store int32, return 0 if overflows
//
// step 2: solutions
//
// the algorithm is straight forward, just get every digit of the number and calculate the reverse number
// the only concern is not overflow.
//
// step 3: coding
//
// step 4: testing
//
// 2147483647 -> 0
// 2147447412 -> 2147447412
// -2147447412 -> -2147447412
// -2147483648 -> 0
// 0 -> 0

#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN)
            return 0;
        if (x < 0)
            return -reverse(-x);
        int overflow_prefix = INT_MAX / 10;
        int overflow_suffix = INT_MAX % 10;
        int y = 0;
        while (x) {
            int r = x % 10;
            if (y > overflow_prefix || (y == overflow_prefix && r > overflow_suffix))
                return 0;
            y = y * 10 + r;
            x /= 10;
        }
        return y;
    }
};
