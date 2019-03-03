#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check row
        for (int i = 0; i < 9; ++i)
            if (!check(board, start_row[i][0], start_row[i][1], row_dir))
                return false;
        // check col
        for (int i = 0; i < 9; ++i)
            if (!check(board, start_col[i][0], start_col[i][1], col_dir))
                return false;
        // check box
        for (int i = 0; i < 9; ++i)
            if (!check(board, start_box[i][0], start_box[i][1], box_dir))
                return false;
        return true;
    }

private:
    bool check(const vector<vector<char>>& board, int row, int col, const int dir[8][2]) {
        vector<bool> used(9, false);
        if (board[row][col] != '.')
            used[board[row][col] - '0'] = true;
        for (int i = 0; i < 8; ++i) {
            row += dir[i][0];
            col += dir[i][1];
            if (board[row][col] == '.')
                continue;
            if (used[board[row][col] - '0'])
                return false;
            used[board[row][col] - '0'] = true;
        }
        return true;
    }

    const int col_dir[8][2] = {{1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}};
    const int row_dir[8][2] = {{0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}};
    const int box_dir[8][2] = {{1, 0}, {1, 0}, {0, 1}, {-1, 0}, {-1, 0}, {0, 1}, {1, 0}, {1, 0}};
    const int start_col[9][2] = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, 8}};
    const int start_row[9][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}};
    const int start_box[9][2] = {{0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}};
};
