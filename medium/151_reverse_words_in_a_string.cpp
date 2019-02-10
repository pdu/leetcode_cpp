// step 1: clarify
//
// 1. remove the tailing or heading spaces
// 2. only keep one space between words
//
// step 2: solutions
//
// 1. reverse the whole string
// 2. for each of the word, reverse it
// 3. for loop to remove the spaces:
//  only keep the space if the previous char is not space
//  and also don't keep the tailing spaces
// 4. resize the string
// time complexity: O(n)
// space complexity: O(1)
//
// step 3: coding
//
// step 4: testing
//
// "" -> ""

#include <string>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int id = 0;
        while (id < s.size()) {
            if (s[id] == ' ') {
                id++;
                continue;
            }
            int end;
            for (end = id; end < s.size(); ++end)
                if (s[end] == ' ')
                    break;
            reverse(s.begin() + id, s.begin() + end);
            id = end + 1;
        }
        id = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (id != 0 && s[i - 1] == ' ')
                    s[id++] = ' ';
                s[id++] = s[i];
            }
        }
        s.resize(id);
    }
};
