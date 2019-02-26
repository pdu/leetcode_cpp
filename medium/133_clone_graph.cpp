#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (hash.find(node) != hash.end())
            return hash[node];
        Node* new_node = new Node();
        hash[node] = new_node;
        new_node->val = node->val;
        for (Node* neighbor: node->neighbors)
            new_node->neighbors.emplace_back(cloneGraph(neighbor));
        return new_node;
    }

private:
    unordered_map<Node*, Node*> hash;
};
