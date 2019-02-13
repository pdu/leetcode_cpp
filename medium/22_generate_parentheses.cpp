// dfs

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string buff;
        dfs(ret, buff, n, 0);
        return ret;
    }

private:
    void dfs(vector<string>& ret, string& buff, int n, int sum) {
        if (sum == 0 && n == 0) {
            ret.emplace_back(buff);
            return;
        }
        if (n > 0) {
            buff.push_back('(');
            dfs(ret, buff, n - 1, sum + 1);
            buff.pop_back();
        }
        if (sum > 0) {
            buff.push_back(')');
            dfs(ret, buff, n, sum - 1);
            buff.pop_back();
        }
    }
};
