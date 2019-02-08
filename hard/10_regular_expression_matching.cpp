// step 1: clarify
//
// string can be empty
//
// step 2: solutions
//
// 1. define the state: f[i][j] = true stand for matching of leading i chars of s and leading j chars of p
// 2. f[i][j] = true only if:
//      s[i - 1] == p[j - 1] and f[i - 1][j - 1] = true
//      or p[j - 1] == '.' and f[i - 1][j - 1] = true
//      or p[j - 1] == '*' and (p[j - 2] == '.' || p[j - 2] == s[i - 1]) and (f[i - 1][j - 2] = true or f[i - 1][j])
//      or p[j - 1] == '*' and f[i][j - 2]
// 3. the boundary cases:
//      if j == 0 and i == 0: true
//      if j == 0 and i != 0: false
//      if i == 0 and j != 0:
//          if p == "?*?*?*": true
//          else: false
//
// step 3: coding
//
// should be very careful about the corner case
//
// step 4: testing
//
// s: ""
// p: "c*c*"
//
// s: "abc"
// p: "abd*c"

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        f_ = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, -1));
        return isMatch(s, p, s.size(), p.size());
    }

private:
    bool isMatch(const string& s, const string& p, int s_len, int p_len) {
        if (f_[s_len][p_len] != -1)
            return f_[s_len][p_len];
        if (p_len == 0 && s_len > 0)
            return f_[s_len][p_len] = 0;
        if (p_len == 0 && s_len == 0)
            return f_[s_len][p_len] = 1;
        if (s_len == 0)
            return f_[s_len][p_len] = (p_len >= 2 && p[p_len - 1] == '*' && isMatch(s, p, s_len, p_len - 2));
        if (s[s_len - 1] == p[p_len - 1] && isMatch(s, p, s_len - 1, p_len - 1))
            return f_[s_len][p_len] = true;
        if (p[p_len - 1] == '.' && isMatch(s, p, s_len - 1, p_len - 1))
            return f_[s_len][p_len] = true;
        if (p_len >= 2 && p[p_len - 1] == '*'
                && (p[p_len - 2] == '.' || p[p_len - 2] == s[s_len - 1])
                && (isMatch(s, p, s_len - 1, p_len) || isMatch(s, p, s_len - 1, p_len - 2)))
            return f_[s_len][p_len] = true;
        if (p_len >= 2 && p[p_len - 1] == '*' && isMatch(s, p, s_len, p_len - 2))
            return f_[s_len][p_len] = true;
        return f_[s_len][p_len] = false;
    }

    vector<vector<int>> f_;
};
