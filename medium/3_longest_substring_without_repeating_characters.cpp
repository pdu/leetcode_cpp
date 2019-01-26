// step 1: clarify
//
// it's substring not subsequence
// only has at most 127 chars or just 26 alphabeta chars
//
// step 2: solutions
//
// the naive way is starting from each position of the string, find the longest substring without repeated chars, just recording the number of each chars
// time complexity: O(n * 26), 26 is the different number of chars
// space complexity: O(26), used to store the number of chars
//
// based on the naive solution, when we find the repeated chars in the tailing, we just move the head forward
// time complexity: O(n)
// space complexity: O(26), used to store the number of chars
//
// step 3: coding
//
// step 4: testing
//
// "" -> 0

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_set<char> chars;
        int head = 0;
        int tail = 0;
        int ret = 1;
        chars.emplace(s[0]);
        while (tail < s.length() - 1) {
            if (chars.find(s[tail + 1]) == chars.end()) {
                chars.emplace(s[++tail]);
                ret = max(ret, tail - head + 1);
            } else
                chars.erase(s[head++]);
        }
        return ret;
    }
};
