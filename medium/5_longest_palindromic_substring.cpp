// step 1: clarify
//
// Q: how long is the string?
// A: at most 1000
//
// step 2: solutions
//
// the naive way is to enumate all the substrings, and check whether it's palindromic or not
// time complexity: O(n^3)
// space complexity: O(1)
//
// for the palindromic string, it's substring s[1, n-1) must be palindromic string and s[0] == s[n-1]
// so we can use dynamic programming to solve the problem.
// time complexity: O(n^2)
// space complexity: O(n^2), can optimise to O(n)
//
// step 3: coding
//
// step 4: testing

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return s;
        int n = s.length();
        int ret_start = 0;
        int ret_len = 1;
        vector<vector<bool>> f(3, vector<bool>(n, true));
        for (int len = 2; len <= n; ++len) {
            if (ret_len < len - 2)
                break;
            int row = len % 3;
            int prev_row = (len - 2) % 3;
            for (int start = 0, end = start + len - 1; end < n; ++start, ++end) {
                f[row][start] = s[start] == s[end] && f[prev_row][start + 1];
                if (f[row][start]) {
                    ret_len = len;
                    ret_start = start;
                }
            }
        }
        return s.substr(ret_start, ret_len);
    }
};
