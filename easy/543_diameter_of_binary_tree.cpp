#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return parseTree(root).first - 1;
    }

private:
    // return: first is diameter, second is the children length
    pair<int, int> parseTree(TreeNode* root) {
        if (root == nullptr)
            return pair<int, int>(0, 0);
        pair<int, int> left = parseTree(root->left);
        pair<int, int> right = parseTree(root->right);
        int diameter = max(left.first, right.first, 1 + left.second + right.second);
        int length = std::max(left.second, right.second) + 1;
        return pair<int ,int>(diameter, length);
    }

    int max(int a, int b, int c) {
        return std::max(a, std::max(b, c));
    }
};
