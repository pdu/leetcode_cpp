// step 1: clarify
//
// step 2: solutions
//
// 1. build the trie tree of the dictionary
// 2. dynamic programming to check whether it can be formed with the words:
//  f[i] = true indicates the prefix i length of the string can be formed with the words
//  f[0] = true
//  the result is f[str.length()]
// time complexity: O(n * m + p * m), n is the string length, m is the word length, p is the dictionary size
// space complexity: O(n + p * m)
//
// step 3: coding
//
// step 4: testing

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
    bool isEnd;
    unordered_map<char, TrieNode*> children;

    TrieNode(): isEnd(false) {}
    ~TrieNode() {
        for (auto iter: children)
            delete iter.second;
    }
};

class Trie {
public:
    void addWord(const string& str) {
        TrieNode* curr = &root;
        for (auto c: str) {
            auto iter = curr->children.find(c);
            if (iter == curr->children.end()) {
                TrieNode* node = new TrieNode();
                curr->children[c] = node;
                curr = node;
            } else 
                curr = iter->second;
        }
        curr->isEnd = true;
    }

    TrieNode* getRoot() {
        return &root;
    }

private:
    TrieNode root;
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (auto& word: wordDict)
            trie.addWord(word);

        vector<bool> f(s.length() + 1, false);
        f[0] = true;
        for (int i = 0; i < s.length(); ++i)
            if (f[i]) {
                TrieNode* curr = trie.getRoot();
                for (int j = i; j < s.length(); ++j) {
                    auto iter = curr->children.find(s[j]);
                    if (iter == curr->children.end())
                        break;
                    curr = iter->second;
                    if (curr->isEnd)
                        f[j + 1] = true;
                }
            }
        return f[s.length()];
    }
};
