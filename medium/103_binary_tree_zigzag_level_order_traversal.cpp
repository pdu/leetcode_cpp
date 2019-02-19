// bfs + stack

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;
        stack<TreeNode*> level;
        level.emplace(root);
        bool order = true; // true: left to right, false: right to left
        while (!level.empty()) {
            vector<int> vals;
            stack<TreeNode*> next_level;
            while (!level.empty()) {
                TreeNode* top = level.top();
                level.pop();
                vals.emplace_back(top->val);
                if (order) {
                    push(next_level, top->left);
                    push(next_level, top->right);
                } else {
                    push(next_level, top->right);
                    push(next_level, top->left);
                }
            }
            ret.emplace_back(vals);
            order = !order;
            level = next_level;
        }
        return ret;
    }

private:
    inline void push(stack<TreeNode*>& level, TreeNode* node) {
        if (node != nullptr)
            level.emplace(node);
    }
};
