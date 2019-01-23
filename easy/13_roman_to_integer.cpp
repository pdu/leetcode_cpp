// step 1: clarify
//
// the meaning is quite clear
//
// step 2: solutions
//
// the algorithm is quite straight forward, just for loop the string and calculate the sum
// time complexity: O(n)
// space complexity: O(1)
//
// but write a lot of if/else/switch is not quite nice, it's better to find the common pattern and make the code cleaner
//
// step 3: coding
//
// step 4: testing
//
// all the cases like: IV IX XL XC CD CM and other normal formats

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(const string& s) {
        if (s.empty())
            return 0;
        int ret = romans_[s[0]];
        for (int i = 1; i < s.length(); ++i) {
            ret += romans_[s[i]];
            auto it = subtracts_.find(s[i]);
            if (it != subtracts_.end() && it->second == s[i - 1])
                ret -= romans_[s[i - 1]] * 2;
        }
        return ret;
    }

private:
    unordered_map<char, int> romans_ = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    unordered_map<char, char> subtracts_ = {{'V', 'I'}, {'X', 'I'}, {'L', 'X'}, {'C', 'X'}, {'D', 'C'}, {'M', 'C'}};
};
