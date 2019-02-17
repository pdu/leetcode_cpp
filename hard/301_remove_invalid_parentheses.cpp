#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int min_remove = minRemove(s);
        unordered_set<string> result_set;
        string buff;
        dfs(s, min_remove, 0, 0, buff, result_set);
        vector<string> ret;
        set2vector(result_set, ret);
        return ret;
    }

private:
    void set2vector(const unordered_set<string>& result_set, vector<string>& ret) {
        ret.resize(result_set.size());
        int id = 0;
        for (auto& line: result_set)
            ret[id++] = line;
    }

    void dfs(const string& s, int min_remove, int id, int sum, string& buff, unordered_set<string>& result_set) {
        if (id == s.length()) {
            if (sum == 0)
                result_set.emplace(buff);
            return;
        }
        if (s[id] != '(' && s[id] != ')') {
            buff.push_back(s[id]);
            dfs(s, min_remove, id + 1, sum, buff, result_set);
            buff.pop_back();
            return;
        }
        if (s[id] == '(') {
            // use it
            buff.push_back(s[id]);
            dfs(s, min_remove, id + 1, sum + 1, buff, result_set);
            buff.pop_back();
            // not use it
            if (min_remove > 0)
                dfs(s, min_remove - 1, id + 1, sum, buff, result_set);
        } else {
            // use it
            if (sum > 0) {
                buff.push_back(s[id]);
                dfs(s, min_remove, id + 1, sum - 1, buff, result_set);
                buff.pop_back();
            }
            // not use it
            if (min_remove > 0)
                dfs(s, min_remove - 1, id + 1, sum, buff, result_set);
        }
    }

    int minRemove(const string& s) {
        int ret = 0;
        int sum = 0;
        for (auto c: s) {
            if (c == '(')
                sum++;
            else if (c == ')' && sum > 0)
                sum--;
            else if (c == ')' && sum == 0)
                ret++;
        }
        ret += sum;
        return ret;
    }
};
