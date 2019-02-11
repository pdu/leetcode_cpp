#include <limits.h>

class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MIN)
            return 1 / myPow(x, INT_MAX) / x;
        if (n < 0)
            return 1 / myPow(x, -n);
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        double p = myPow(x, n >> 1);
        if ((n&1) == 0)
            return p * p;
        else
            return p * p * x;
    }
};
