#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode(): isEnd(false) {};
    ~TrieNode() {
        for (auto& it: children)
            delete it.second;
    }
};

class Trie {
public:
    TrieNode* get() {
        return &root;
    }

    void add(const string& s) {
        TrieNode* curr = &root;
        for (auto c: s) {
            if (curr->children.find(c) == curr->children.end())
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }
private:
    TrieNode root;
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (auto& word: wordDict) {
            reverse(word.begin(), word.end());
            trie.add(word);
        }

        unordered_map<int, vector<vector<int>>> all_paths;
        dp(s, s.length() - 1, trie, all_paths);
        vector<string> ret;
        for (auto& path: all_paths[s.length() - 1]) {
            string buff(s.substr(0, path[0] + 1));
            for (int i = 1; i < path.size(); ++i) {
                buff.push_back(' ');
                buff.insert(buff.end(), s.begin() + path[i - 1] + 1, s.begin() + path[i] + 1);
            }
            ret.emplace_back(buff);
        }
        return ret;
    }

private:
    void dp(const string& s, int id, Trie& trie, unordered_map<int, vector<vector<int>>>& all_paths) {
        all_paths.emplace(id, vector<vector<int>>());
        TrieNode* curr = trie.get();
        for (int i = id; i >= 0; --i) {
            if (curr->children.find(s[i]) == curr->children.end())
                break;
            curr = curr->children[s[i]];
            if (!curr->isEnd)
                continue;
            if (i == 0) {
                vector<int> path(1, id);
                all_paths[id].emplace_back(path);
                continue;
            }
            if (all_paths.find(i - 1) == all_paths.end())
                dp(s, i - 1, trie, all_paths);
            for (auto path: all_paths[i - 1]) {
                path.emplace_back(id);
                all_paths[id].emplace_back(path);
            }
        }
    }
};
