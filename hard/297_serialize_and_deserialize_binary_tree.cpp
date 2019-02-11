// step 1: clarify
//
// step 2: solution
//
// 1. initial offset=0
// 2. use 4 bytes to store the root value, offset += 4
// 3. use 1 byte to store whether has left-tree or right-tree.
//  bits: 01234567, by default v = 0
//  if has left-tree: v&1 != 0
//  if has right-tree: v&2 != 0
// 4. if has left-tree, process the left-tree and update the offset
// 5. if has right-tree, process the right-tree and update the offset
// 6. root = nullptr, means buffer length = 0
//
// step 3: coding
//
// step 4: testing
//
// empty tree -> ""

#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "";
        string ret = int2str(root->val);
        char sign = 0;
        if (root->left != nullptr)
            sign |= 1;
        if (root->right != nullptr)
            sign |= 2;
        ret.append(char2str(sign));
        if (root->left != nullptr)
            ret.append(serialize(root->left));
        if (root->right != nullptr)
            ret.append(serialize(root->right));
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        int offset = 0;
        return deserialize(data, offset);
    }

private:
    string char2str(char v) {
        string s(1, ' ');
        memcpy((char*)s.c_str(), &v, 1);
        return s;
    }

    char str2char(const string& buff) {
        char v;
        memcpy(&v, buff.c_str(), 1);
        return v;
    }

    string int2str(int v) {
        string s(4, ' ');
        memcpy((char*)s.c_str(), &v, 4);
        return s;
    }

    int str2int(const string& buff) {
        int v;
        memcpy(&v, buff.c_str(), 4);
        return v;
    }

    TreeNode* deserialize(const string& data, int& offset) {
        if (offset == data.size())
            return nullptr;
        int val = str2int(data.substr(offset, 4));
        offset += 4;
        char sign = str2char(data.substr(offset, 1));
        offset += 1;
        TreeNode* root = new TreeNode(val);
        if ((sign & 1) != 0)
            root->left = deserialize(data, offset);
        if ((sign & 2) != 0)
            root->right = deserialize(data, offset);
        return root;
    }
};
