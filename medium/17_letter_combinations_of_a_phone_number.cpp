// step 1: clarify
//
// step 2: solution
//
// depth first search
//
// step 3: coding
//
// step 4: testing

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(const string& digits) {
        vector<string> ret;
        if (digits.empty())
            return ret;
        string buff;
        dfs(digits, 0, ret, buff);
        return ret;
    }

private:
    void dfs(const string& digits, int id, vector<string>& ret, string& buff) {
        if (id == digits.size()) {
            ret.push_back(buff);
            return;
        }
        for (auto c: phone[digits[id] - '0']) {
            buff.push_back(c);
            dfs(digits, id + 1, ret, buff);
            buff.pop_back();
        }
    }

    const vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
