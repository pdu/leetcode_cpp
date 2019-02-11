// step 1: clarify
//
// step 2: solution
//
// dfs
//
// step 3: coding
//
// step 4: testing

#include <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;
        for (int row = 0; row < grid.size(); ++row)
            for (int col = 0; col < grid[0].size(); ++col)
                if (grid[row][col] == 1) {
                    grid[row][col] = 0;
                    int num = 1;
                    dfs(grid, row, col, num);
                    ret = max(ret, num);
                }
        return ret;
    }

private:
    void dfs(vector<vector<int>>& grid, int row, int col, int& num) {
        for (int d = 0; d < 4; ++d) {
            int next_row = row + dir[d][0];
            int next_col = col + dir[d][1];
            if (next_row >= 0 && next_row < grid.size() && next_col >= 0 && next_col < grid[0].size() && grid[next_row][next_col] == 1) {
                grid[next_row][next_col] = 0;
                num++;
                dfs(grid, next_row, next_col, num);
            }
        }
    }

    const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};
