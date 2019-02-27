// use trie
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

#define MAX_QUERY_COUNT 3

bool query_comp(const pair<int, string>& a, const pair<int, string>& b) {
    return a > b;
}

struct TrieNode {
    int count;
    vector<pair<int, string>> top_queries;
    unordered_map<char, TrieNode*> children;

    TrieNode(): count(0) {}
    
    ~TrieNode() {
        for (auto& it: children)
            delete it.second;
    }

    void addQuery(const string& sentence, int time) {
        for (auto& query: top_queries)
            if (query.second == sentence) {
                query.first = time;
                return;
            }
        top_queries.emplace_back(time, sentence);
        sort(top_queries.begin(), top_queries.end(), query_comp);
        if (top_queries.size() > MAX_QUERY_COUNT)
            top_queries.resize(MAX_QUERY_COUNT);
    }
};

class Trie {
public:
    TrieNode* get() {
        return &root;
    }
    
    void add(const string& sentence, int time) {
        TrieNode* curr_node = &root;
        for (auto c: sentence) {
            auto it = curr_node->children.find(c);
            if (it == curr_node->children.end()) {
                TrieNode* new_node = new TrieNode();
                new_node->top_queries.emplace_back(time, sentence);
                curr_node->children[c] = new_node;
                curr_node = new_node;
            } else {
                curr_node = it->second;
                curr_node->addQuery(sentence, time);
            }
        }
        curr_node->count = time;
    }

private:
    TrieNode root;
};


class AutocompleteSystem {
public:
    AutocompleteSystem(const vector<string>& sentences, const vector<int>& times): query_count(0) {
        for (int i = 0; i < sentences.size(); ++i)
            trie.add(sentences[i], times[i]);
        trie_node = trie.get();
    }

    vector<string> input(char c) {
        vector<string> ret;
        if (c == '#') {
            trie.add(query, query_count + 1);
            query_count = 0;
            trie_node = trie.get();
            return ret;
        }
        query.push_back(c);
        if (trie_node == nullptr)
            return ret;
        auto it = trie_node->children.find(c);
        if (it == trie_node->children.end()) {
            query_count = 0;
            trie_node = nullptr;
            return ret;
        }
        trie_node = it->second;
        query_count = trie_node->count;
        for (auto& query: trie_node->top_queries)
            ret.emplace_back(query.second);
        return ret;
    }

private:
    Trie trie;
    TrieNode* trie_node;
    string query;
    int query_count;
};
