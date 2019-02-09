// step 1: clarify
//
// input range is 0 to 3999
//
// step 2: solution
//
// straightforward solution
//
// step 3: coding
//
// find the common pattern to write the elegant code
//
// step 4: testing

#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        Base bases[4] = {{1000, 'M', ' ', ' '}, {100, 'C', 'D', 'M'}, {10, 'X', 'L', 'C'}, {1, 'I', 'V', 'X'}};
        string ret;
        for (auto& base: bases) {
            int c = num / base.base;
            num %= base.base;
            if (c == 9) {
                append(ret, base.one, 1);
                append(ret, base.ten, 1);
            } else if (c >= 5) {
                append(ret, base.five, 1);
                append(ret, base.one, c - 5);
            } else if (c == 4) {
                append(ret, base.one, 1);
                append(ret, base.five, 1);
            } else 
                append(ret, base.one, c);
        }
        return ret;
    }

private:
    struct Base {
        int base;
        char one;
        char five;
        char ten;
        Base() {}
        Base(int b, char o, char f, char t): base(b), one(o), five(f), ten(t) {}
    };

    void append(string& ret, char c, int n) {
        while (n--)
            ret.push_back(c);
    }
};
