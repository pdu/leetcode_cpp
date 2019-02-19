// dfs

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty())
            return true;
        if (board.empty() || board[0].empty())
            return false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (dfs(board, visited, word, i, j, 1))
                        return true;
                    visited[i][j] = false;
                }
        return false;
    }

private:
    bool dfs(const vector<vector<char>>& board, vector<vector<bool>>& visited, const string& word, int row, int col, int id) {
        if (id == word.size())
            return true;
        for (int d = 0; d < 4; ++d) {
            int next_row = row + dir[d][0];
            int next_col = col + dir[d][1];
            if (inRange(board, next_row, next_col) && board[next_row][next_col] == word[id] && !visited[next_row][next_col]) {
                visited[next_row][next_col] = true;
                if (dfs(board, visited, word, next_row, next_col, id + 1))
                    return true;
                visited[next_row][next_col] = false;
            }
        }
        return false;
    }

    inline bool inRange(const vector<vector<char>>& board, int row, int col) {
        return row >= 0 && row < board.size() && col >= 0 && col < board[0].size();
    }

    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
