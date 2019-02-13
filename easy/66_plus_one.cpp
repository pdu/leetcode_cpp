#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            ret.emplace_back((digits[i] + carry) % 10);
            carry = (digits[i] + carry) / 10;
        }
        if (carry != 0)
            ret.emplace_back(carry);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
