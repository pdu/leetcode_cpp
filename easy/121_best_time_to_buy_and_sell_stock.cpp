// step 1: clarify
//
// step 2: solution
//
// for loop the array, recording the current minimum value
// calculate the profit if selling at today and buying at the previous minimum value, choose the maximum profit
// time complexity: O(n)
// space complexity: O(1)
//
// step 3: coding
//
// step 4: testing

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int ret = 0;
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            ret = max(ret, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return ret;
    }
};
