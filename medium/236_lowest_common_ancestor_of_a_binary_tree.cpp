struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        if (root == p || root == q)
            return root;
        TreeNode* left_ret = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_ret = lowestCommonAncestor(root->right, p, q);
        if (left_ret == nullptr && right_ret == nullptr)
            return nullptr;
        else if (left_ret == nullptr && right_ret != nullptr)
            return right_ret;
        else if (left_ret != nullptr && right_ret == nullptr)
            return left_ret;
        else
            return root;
    }
};
