#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> nodes;
        push(nodes, root);
        while (!nodes.empty()) {
            TreeNode* top = nodes.top();
            nodes.pop();
            ret.emplace_back(top->val);
            push(nodes, top->right);
        }
        return ret;
    }

    void push(stack<TreeNode*>& nodes, TreeNode* root) {
        while (root != nullptr) {
            nodes.emplace(root);
            root = root->left;
        }
    }
};
