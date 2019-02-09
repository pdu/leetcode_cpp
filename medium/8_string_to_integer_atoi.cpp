// step 1: clarify
//
// 1. may has initial whitespaces
// 2. may has an optional plus or minus sign
// 3. ignore the invalid chars after the number
// 4. if it's not a valid number, return 0
// 5. if it's out of int32 range, return INT_MIN or INT_MAX
//
// step 2: solution
//
// 1. watch out the corner case
// 2. make sure it will not overflow
//
// step 3: coding
//
// step 4: testing
//
// 0 -> 0
// -0 -> 0
// +0 -> 0
// 000123 -> 123
// 2147483647
// -2147483648
// 2147483648
// -2147483649
// invalid numbers

#include <string>
#include <climits>

using namespace std;

#define MAX_PREFIX 214748364
#define MAX_SUFFIX 7
#define MIN_PREFIX -214748364
#define MIN_SUFFIX 8

class Solution {
public:
    int myAtoi(const string& str) {
        int start_id = skipWhitespaces(str);
        if (start_id == str.length())
            return 0;
        int ret = skipSign(str, start_id);
        if (start_id == str.length())
            return 0;
        skipZeros(str, start_id);
        if (start_id == str.length())
            return 0;
        if (!isDigit(str[start_id]))
            return 0;
        ret *= str[start_id++] - '0';
        for (int i = start_id; i < str.length(); ++i) {
            if (!isDigit(str[i]))
                break;
            int d = str[i] - '0';
            if (ret > MAX_PREFIX || (ret == MAX_PREFIX && d > MAX_SUFFIX))
                return INT_MAX;
            if (ret < MIN_PREFIX || (ret == MIN_PREFIX && d > MIN_SUFFIX))
                return INT_MIN;
            ret = ret * 10 + (ret > 0 ? d : -d);
        }
        return ret;
    }

private:
    inline bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    void skipZeros(const string& str, int& start_id) {
        for (; start_id < str.length(); ++start_id)
            if (str[start_id] != '0')
                break;
    }

    int skipWhitespaces(const string& str) {
        for (int i = 0; i < str.length(); ++i)
            if (str[i] != ' ')
                return i;
        return str.length();
    }

    int skipSign(const string& str, int& start_id) {
        int ret = 1;
        if (str[start_id] == '+')
            start_id++;
        else if (str[start_id] == '-') {
            start_id++;
            ret = -1;
        }
        return ret;
    }
};
