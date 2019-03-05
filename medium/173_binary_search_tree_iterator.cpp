#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        pushNode(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* top = nums.top();
        nums.pop();
        pushNode(top->right);
        return top->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nums.empty();
    }

private:
    void pushNode(TreeNode* root) {
        while (root != nullptr) {
            nums.emplace(root);
            root = root->left;
        }
    }

    stack<TreeNode*> nums;
};
