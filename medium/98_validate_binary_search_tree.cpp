#include <stdint.h>
#include <limits.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, int64_t(INT_MIN) - 1, int64_t(INT_MAX) + 1);
    }

private:
    bool isValidBST(TreeNode* root, int64_t min_value, int64_t max_value) {
        if (root == nullptr)
            return true;
        return root->val > min_value && root->val < max_value 
            && isValidBST(root->left, min_value, root->val) 
            && isValidBST(root->right, root->val, max_value);
    }
};
