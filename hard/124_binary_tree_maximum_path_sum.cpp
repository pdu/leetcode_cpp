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
    int maxPathSum(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int sum = 0;
        return maxPathSum(root, sum);
    }

private:
    int maxPathSum(TreeNode* root, int &sum) {
        int ret = root->val;
        int path = root->val;
        sum = max(0, root->val);
        if (root->left != nullptr) {
            parseChild(root->left, root->val, sum, ret, path);
        }
        if (root->right != nullptr) {
            parseChild(root->right, root->val, sum, ret, path);
        }
        return max(ret, path);
    }

    void parseChild(TreeNode* child, int val, int& sum, int& ret, int& path) {
        int child_sum;
        int child_ret = maxPathSum(child, child_sum);;
        sum = max(sum, child_sum + val);
        ret = max(ret, child_ret);
        path += child_sum;
    }
};
