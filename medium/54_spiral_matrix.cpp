// step 1: clarify
//
// step 2: solution
//
// 1. first loop the outer board
// 2. process the inner matrix
// pay attention to the case when row or col = 1
// time complexity: O(n * m)
// space complexity: O(1)
//
// step 3: coding
//
// step 4: testing

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.empty() || matrix[0].empty())
            return ret;
        ret.resize(matrix.size() * matrix[0].size());
        fill(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, ret, 0);
        return ret;
    }

private:
    void fill(vector<vector<int>>& matrix, int left_row, int left_col, int right_row, int right_col, vector<int>& ret, int id) {
        if (left_row > right_row || left_col > right_col)
            return;
        if (left_row == right_row) {
            for (int col = left_col; col <= right_col; ++col)
                ret[id++] = matrix[left_row][col];
            return;
        } 
        if (left_col == right_col) {
            for (int row = left_row; row <= right_row; ++row)
                ret[id++] = matrix[row][left_col];
            return;
        }
        for (int col = left_col; col <= right_col; ++col)
            ret[id++] = matrix[left_row][col];
        for (int row = left_row + 1; row < right_row; ++row)
            ret[id++] = matrix[row][right_col];
        for (int col = right_col; col >= left_col; --col)
            ret[id++] = matrix[right_row][col];
        for (int row = right_row - 1; row > left_row; --row)
            ret[id++] = matrix[row][left_col];
        fill(matrix, left_row + 1, left_col + 1, right_row - 1, right_col - 1, ret, id);
    }
};
