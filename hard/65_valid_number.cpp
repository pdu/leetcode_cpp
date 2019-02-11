// step 1: clarify
//
// 1. can have leading or tailing spaces
// 2. can have only one decimal point
// 3. can have "e", before e can be a decimal or integer, after e can be integer, before and after "e" must has numbers
// 4. can only has one "+" or "-"
//
// step 2: solutions
//
// 1. remove the heading and tailing spaces
// 2. false: if has space inside the string
// 3. check whether has "e" or not
// 4. check whether is decimal or integer
//
// step 3: coding
//
// step 4: testing
//
// ".1" -> true
// "3." -> true
// "+.8" -> true

#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if (!isSpaceValid(s))
            return false;
        int e_count = count(s.begin(), s.end(), 'e');
        if (e_count == 0)
            return isValidDecimal(s);
        else if (e_count == 1) {
            int e_id = s.find('e');
            string first = s.substr(0, e_id);
            string second = s.substr(e_id + 1, s.length() - e_id - 1);
            return isValidDecimal(first) && isValidInteger(second);
        } else
            return false;
    }

private:
    bool isSpaceValid(string& s) {
        int start;
        for (start = 0; start < s.size(); ++start)
            if (s[start] != ' ')
                break;
        int end;
        for (end = s.size() - 1; end >= 0; --end)
            if (s[end] != ' ')
                break;
        if (start > end)
            return false;
        for (int i = start + 1; i < end; ++i)
            if (s[i] == ' ')
                return false;
        s = s.substr(start, end - start + 1);
        return true;
    }

    bool isValidPositive(const string &s) {
        if (s.empty())
            return false;
        for (auto c: s)
            if (c < '0' || c > '9')
                return false;
        return true;
    }

    bool isValidInteger(string& s) {
        if (s.empty())
            return false;
        if (s[0] == '+' || s[0] == '-')
            return isValidPositive(s.substr(1, s.length() - 1));
        return isValidPositive(s);
    }

    bool isValidDecimal(string& s) {
        if (s.empty())
            return false;
        if (s[0] == '+' || s[0] == '-')
            s = s.substr(1, s.size() - 1);
        int dot_count = count(s.begin(), s.end(), '.');
        if (dot_count == 0)
            return isValidInteger(s);
        else if (dot_count == 1) {
            int dot_id = s.find('.');
            string first = s.substr(0, dot_id);
            string second = s.substr(dot_id + 1, s.length() - dot_id - 1);
            return (first.empty() || isValidInteger(first)) && (second.empty() || isValidPositive(second)) && (!first.empty() || !second.empty());
        } else
            return false;
    }
};
