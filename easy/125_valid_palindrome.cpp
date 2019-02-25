#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (!isAlphanumeric(s[left]))
                left++;
            else if (!isAlphanumeric(s[right]))
                right--;
            else if (toLower(s[left]) == toLower(s[right])) {
                left++;
                right--;
            } else
                return false;
        }
        return true;
    }

private:
    inline bool isAlphanumeric(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }

    inline char toLower(char c) {
        return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
    }
};
