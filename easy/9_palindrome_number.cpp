// step 1: clarify
//
// Q: is negative number a palindrome?
// A: no, -121 reverse is 121- which is not palindrome
//
// step 2: solutions
//
// first, exclude the special cases:
//  1. negative number: false
//  2. zero: true
//
// then transfer the number into a string and check whether the string is palindrome or not
// let n = length of the string
// time complexity: O(n)
// space complexity: O(n)
//
// another approach is reverse the number and check the values are equal or not, for example:
//  reverse(1221) = 1221, true
//  reverse(122) = 221, false
// but in this case, we should be careful about the int32 overflow:
//  reverse(2147483647) = 7463847412, simple way to use int64 here
// time complexity: O(n)
// space complexity: O(1)
//
// compare these two solutions, because the length of the string is at most 12, the time and space complexity are almost the same
// but solution 2 should be easier to write the code
//
// step 3: coding
//
// step 4: testing
//  -1: false
//  0: true
//  1222: false
//  2147483647: false
//  2147447412: true

#include <cstdint>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        return reverse(x) == x;
    }

private:
    int64_t reverse(int x) {
        int64_t ret = 0;
        while (x) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return ret;
    }
};

int main(int argc, char* argv[]) {
    Solution sln;
    unordered_map<int, bool> nums({{-1, false}, {0, true}, {1222, false}, {2147483647, false}, {2147447412, true}});
    for (auto& num: nums)
        if (num.second != sln.isPalindrome(num.first))
            cout << num.first << " expected: " << num.second << endl;
    return 0;
}
