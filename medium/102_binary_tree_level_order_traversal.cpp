#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;
        queue<TreeNode*> nodes;
        nodes.emplace(root);
        while (!nodes.empty()) {
            ret.emplace_back(vector<int>());
            queue<TreeNode*> nexts;
            while (!nodes.empty()) {
                TreeNode* top = nodes.front();
                nodes.pop();
                ret.back().emplace_back(top->val);
                if (top->left != nullptr)
                    nexts.emplace(top->left);
                if (top->right != nullptr)
                    nexts.emplace(top->right);
            }
            nodes = nexts;
        }
        return ret;
    }
};
