// dfs

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<bool> visited(nums.size(), false);
        vector<int> buff;
        dfs(nums, 0, visited, buff, ret);
        return ret;
    }

private:
    void dfs(const vector<int>& nums, int id, vector<bool>& visited, vector<int>& buff, vector<vector<int>>& ret) {
        if (id == nums.size()) {
            ret.emplace_back(buff);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
            if (!visited[i]) {
                visited[i] = true;
                buff.emplace_back(nums[i]);
                dfs(nums, id + 1, visited, buff, ret);
                buff.pop_back();
                visited[i] = false;
            }
    }
};
