// dynamic programming
// f[i][j]: i, j is len
//  if word1[i-1] == word2[j-1]: f[i-1][j-1]
//  else:
//      replace: f[i-1][j-1] + 1
//      insert: f[i][j-1] + 1
//      remove: f[i-1][j] + 1
//  if i==0 or j==0: f[i][j] = max(i, j)

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> f(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return find(word1, word2, word1.size(), word2.size(), f);
    }

private:
    int find(const string& word1, const string& word2, int len1, int len2, vector<vector<int>>& f) {
        if (f[len1][len2] >= 0)
            return f[len1][len2];
        if (len1 == 0 || len2 == 0)
            return f[len1][len2] = max(len1, len2);
        if (word1[len1 - 1] == word2[len2 - 1])
            return f[len1][len2] = find(word1, word2, len1 - 1, len2 - 1, f);
        return f[len1][len2] = 1 + min(find(word1, word2, len1 - 1, len2 - 1, f), 
                find(word1, word2, len1, len2 - 1, f), find(word1, word2, len1 - 1, len2, f));
    }

    int min(int a, int b, int c) {
        return std::min(a, std::min(b, c));
    }
};
