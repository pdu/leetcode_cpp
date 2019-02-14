// step 1: clarify
//
// step 2: solutions
//
// 1. for loop the starting point of each valid parentheses
// 2. init the sum = 0, and +1 for '(' and -1 for ')', if sum < 0, break because it's invalid,
// 3. return the maximum length when sum = 0 which is valid parentheses
// time complexity: O(n^2)
// space complexity: O(1)
//
// define f[i] is the longest valid parentheses ending with i-th element
// 1. init f[i] = 0
// 2. if str[i] == ')' and str[i - 1 - f[i - 1]] == '('
//      f[i] = 2 + f[i - 1] + f[i - 2 - f[i - 1]]
// 3. ret = max(f[i])
// time complexity: O(n)
// space complexity: O(n)

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(const string& s) {
        vector<int> f(s.size(), 0);
        int ret = 0;
        for (int i = 1; i < s.size(); ++i) {
            int prev_id = i - 1 - f[i - 1];
            if (prev_id >= 0 && s[i] == ')' && s[prev_id] == '(') {
                f[i] = 2 + f[i - 1];
                if (prev_id >= 1)
                    f[i] += f[prev_id - 1];
                ret = max(ret, f[i]);
            }
        }
        return ret;
    }
};
