// step 1: clarify
//
// quite strightforward, very clear
//
// step 2: solutions
//
// from the first index to the end, check whether all the strings have the same char at the same index, if not, break
// time complexity: O(n * m), n is the number of strings, m is the length of string
// space complexity: O(1)
//
// step 3: coding
//
// step 4: testing

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        int len = 0;
        for (len = 0; len < strs[0].length(); ++len) {
            bool is_same = true;
            for (int i = 1; i < strs.size(); ++i)
                if (strs[i].length() <= len || strs[i][len] != strs[i - 1][len]) {
                    is_same = false;
                    break;
                }
            if (!is_same)
                break;
        }
        return strs[0].substr(0, len);
    }
};
