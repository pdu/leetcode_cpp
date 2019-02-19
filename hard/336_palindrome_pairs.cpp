// trie
// or hash table

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

bool isPalin(const string& word, int left, int right) {
    if (left > right)
        return false;
    for (; left < right; ++left, --right)
        if (word[left] != word[right])
            return false;
    return true;
}

struct TrieNode {
    int end_id;
    unordered_set<int> palins;
    unordered_map<char, TrieNode*> children;

    TrieNode(): end_id(-1) {}

    ~TrieNode() {
        for (auto iter: children)
            delete iter.second;
    }
};

class Trie {
public:
    TrieNode* get() {
        return &root;
    }

    void addWord(const string& word, int id) {
        if (word.empty()) {
            root.end_id = id;
            return;
        }
        TrieNode* curr = &root;
        if (isPalin(word, 0, word.size() - 1))
            curr->palins.emplace(id);
        for (int i = word.size() - 1; i >= 0; --i) {
            auto it = curr->children.find(word[i]);
            if (it == curr->children.end()) {
                TrieNode* node = new TrieNode();
                curr->children[word[i]] = node;
                curr = node;
            } else
                curr = it->second;
            if (isPalin(word, 0, i - 1))
                curr->palins.emplace(id);
        }
        curr->end_id = id;
    }

private:
    TrieNode root;
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie trie;
        for (int i = 0; i < words.size(); ++i)
            trie.addWord(words[i], i);
        vector<vector<int>> ret;
        for (int i = 0; i < words.size(); ++i) {
            string& word = words[i];
            TrieNode* curr = trie.get();
            if (curr->end_id >= 0 && curr->end_id != i && isPalin(word, 0, word.size() - 1))
                ret.emplace_back(vector<int>({i, curr->end_id}));
            for (int j = 0; j < word.size(); ++j) {
                auto it = curr->children.find(word[j]);
                if (it == curr->children.end()) {
                    curr = nullptr;
                    break;
                }
                curr = it->second;
                if (curr->end_id >= 0 && curr->end_id != i && (j == word.size() - 1 || isPalin(word, j + 1, word.size() - 1)))
                    ret.emplace_back(vector<int>({i, curr->end_id}));
            }
            if (curr != nullptr) {
                for (auto id: curr->palins)
                    if (id != i)
                        ret.emplace_back(vector<int>({i, id}));
            }
        }
        return ret;
    }
};

int main() {
    vector<string> words = {"","adijdce","i","egjgc","jcjcj","f","hfcbdah","bhb","afie","fegc","fcbeg","fihbaga","ehgffg","gjih","ejdejg","gj","a","fbh","hg","addi"};
    // vector<string> words = {"bbbbbabbabbbb","baabbaa","bbab","bbbabbaaab","abababbbbbab","abb","baaaabbb","babbaaaba","aab","aaaab","baabbbbabbaaaba","baaab","abbbab","abaabbbabbabba","aa","aabbbaabba","aaabbbbbaaabbbb","bbaaaaba","ababaaa","aaaaa","aaaaabbbbaaaba","abbabbbaabbaabbb","bbaba","aaaaabbbabbbbaaaab","abbbaa","bbbabbaaa","bbbaaabaabbbaaaaabaa","aaaabbabb","ababbababbbab","aaaaababaababbbabaaa","ba","bbbbababbbabab","baaaba","aababbaaabbb","aabbaaabbabaaababaab","abbbb","babaabaaababb","bbbbabaaaab","babbbbb","babaaba","aaba","abababba","a","bb","abaaab","babbabaababbabaaba","aaaaaababbbabaaabaa","baabaaabb","b","bbaaaabbb","abaaaaabaabbbaa","ab","bababaaaba","aabababb","ababaabbaababba","bbb","ababbaabababbbbbabb","bbbbb","abbbbaabaaaabb","baba","bbaabbabaaababaabbaa","bbaabaabbabbaab","bbbaabbab","babbbbbaaaaabaa","abbbbbbabbbabb","abaa","bbbbaababaab","abaaababa","aaaababaaababbaaba","bbabbbabbbbbbaab","abbabbabaabbabbbba","abbbbbaabbbaaabaaaa","bbaabababb","aaabababaabbaaaaaaab","ababbaabaaababb","abbbbabaaabbaaabbab","aababababbabaaa","baabbaabbbaaaaaa","bbbbbbbabbabbbbbb","bbbabbabbabbabaabba","babbbbabaaaabbabaab","baabaabaabababaaabba","bbaaaabbbbabbbaaaa","aaaaabaabaa","bbabaaabbbabaa","baaabaaaaaab","ababbbbbbbabaaaba","abbbabaababbbbbaaa","baaaaaabab","aabbabba","baaabbaabbbbaba","aaaaabba","babaaabbba","bbbbab","bbbbaabbaabab","baa","baababaa","abbbbb","babbaa","abbbabbaa"};
    Solution sln;
    vector<vector<int>> ret = sln.palindromePairs(words);
    for (auto& pair: ret)
        cout << pair[0] << " " << pair[1] << endl;
    return 0;
}
