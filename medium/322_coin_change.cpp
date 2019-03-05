#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, INT_MAX);
        f[0] = 0;
        for (auto coin: coins)
            for (int n = 0; n <= amount - coin; ++n)
                if (f[n] < INT_MAX)
                    f[n + coin] = min(f[n + coin], f[n] + 1);
        return f[amount] == INT_MAX ? -1 : f[amount];
    }
};
