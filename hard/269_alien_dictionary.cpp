// toplogical sort

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    string letterOrder(vector<string>& wordList) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> degree;
        build(wordList, adj, degree);
        string buff;
        queue<char> q;
        for (auto& it: degree)
            if (it.second == 0)
                q.emplace(it.first);
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            buff.push_back(c);
            auto it = adj.find(c);
            if (it == adj.end())
                continue;
            for (auto c: it->second) {
                degree[c]--;
                if (degree[c] == 0)
                    q.emplace(c);
            }
        }
        return q.empty() ? buff : "";
    }

private:
    void build(const vector<string>& wordList, unordered_map<char, unordered_set<char>>& adj, unordered_map<char, int>& degree) {
        for (int i = 1; i < wordList.size(); ++i) {
            const string& first = wordList[i - 1];
            const string& second = wordList[i];
            for (int k = 0; k < first.size() && k < second.size(); ++k)
                if (first[k] != second[k]) {
                    addEdge(first[k], second[k], adj, degree);
                    break;
                }
        }
    }

    void addEdge(char a, char b, unordered_map<char, unordered_set<char>>& adj, unordered_map<char, int>& degree) {
        auto it = adj.find(a);
        if (it == adj.end()) {
            adj.emplace(a, unordered_set<char>({b}));
            addDegree(b, degree);
            return;
        }
        auto it2 = it->second.find(b);
        if (it2 == it->second.end()) {
            it->second.emplace(b);
            addDegree(b, degree);
        }
    }

    void addDegree(char b, unordered_map<char, int>& degree) {
        auto it = degree.find(b);
        if (it == degree.end())
            degree[b] = 1;
        else
            it->second++;
    }
};
