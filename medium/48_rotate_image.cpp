// flip diagonal, then flip horizontal
// 
// 1 2 3
// 4 5 6
// 7 8 9
//
// -->
//
// 1 4 7
// 2 5 8
// 3 6 9
//
// -->
//
// 7 4 1
// 8 5 2
// 9 6 3

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 1; i < n; ++i) {
            int row = i;
            for (int col = 0; col < i; ++col) {
                // row, col opposite col row
                // 1,0 -> 0,1 2,1 -> 1,2
                swap(matrix[row][col], matrix[col][row]);
            }
        }
        for (int row = 0; row < n; ++row) {
            int left_col = 0;
            int right_col = n - 1;
            while (left_col < right_col) {
                swap(matrix[row][left_col], matrix[row][right_col]);
                left_col++;
                right_col--;
            }
        }
    }
};
