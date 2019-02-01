// step 1: clarify
//
// step 2: solutions
//
// from any of the positon to do the dfs search
// time complexity: O(n^2)
// space complexity: O(n^2)
//
// step 3: coding
//
// step 4: testing

#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int ret = 0;
        for (int row = 0; row < grid.size(); ++row)
            for (int col = 0; col < grid[0].size(); ++col)
                if (grid[row][col] == '1' && !visited[row][col]) {
                    ret++;
                    visited[row][col] = true;
                    travel(grid, visited, row, col);
                }
        return ret;
    }

private:
    void travel(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        for (int d = 0; d < 4; ++d) {
            int next_row = row + dir[d][0];
            int next_col = col + dir[d][1];
            if (inRange(grid.size(), grid[0].size(), next_row, next_col)
                    && grid[next_row][next_col] == '1' && !visited[next_row][next_col]) {
                visited[next_row][next_col] = true;
                travel(grid, visited, next_row, next_col);
            }
        }
    }

    inline bool inRange(int n, int m, int row, int col) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
};
