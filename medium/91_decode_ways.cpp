// step 1: clarify
//
// step 2: solutions
//
// dynamic programming
// 1. f[len] means the ways to decode the string of "len" length
// 2. f[0] = 1
// 3. f[i] -> f[i+1] if str[i] in range [1, 9]
//    f[i] -> f[i+2] if str[i,i+1] in range [10, 26]
// time complexity: O(n)
// space complexity: O(1), can use f[3] to rotate all the states
//
// step 3: coding
//
// step 4: testing

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> f(3, 0);
        f[0] = 1;
        for (int len = 1; len <= s.length(); ++len) {
            // len - 1, len - 2
            f[len % 3] = 0;
            if (s[len - 1] >= '1' && s[len - 1] <= '9')
                f[len % 3] += f[(len - 1) % 3];
            if (len - 2 >= 0 && ((s[len - 2] == '1' && s[len - 1] >= '0' && s[len - 1] <= '9') || (s[len - 2] == '2' && s[len - 1] >= '0' && s[len - 1] <= '6')))
                f[len % 3] += f[(len - 2) % 3];
        }
        return f[s.length() % 3];
    }
};
