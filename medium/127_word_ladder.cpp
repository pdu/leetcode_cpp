#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict;
        for (auto& word: wordList)
            wordDict.emplace(word);
        queue<string> q;
        unordered_map<string, int> hash;
        q.emplace(beginWord);
        hash[beginWord] = 1;
        while (!q.empty()) {
            string top = q.front();
            q.pop();
            int count = hash[top] + 1;
            for (int i = 0; i < top.size(); ++i) {
                string next = top;
                for (char c = 'a'; c <= 'z'; ++c) {
                    next[i] = c;
                    if (hash.find(next) != hash.end() || wordDict.find(next) == wordDict.end())
                        continue;
                    if (endWord == next)
                        return count;
                    q.emplace(next);
                    hash[next] = count;
                }
            }
        }
        return 0;
    }
};
