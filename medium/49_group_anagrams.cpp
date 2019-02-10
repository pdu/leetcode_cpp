// step 1: clarify
//
// step 2: solution
//
// 1. sort the array, for each of the string, sort it internally before compare
// time complexity: O(n * logn * m), m is the string length
// space complexity: O(1)
//
// 2. store the array into a hash table, sort the string internally to be the hash key
// time complexity: O(n * m), m is the string length
// space complexity: O(n * m)
//
// step 3: coding
//
// step 4: testing

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> hash;
        for (int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            auto iter = hash.find(str);
            if (iter == hash.end()) {
                vector<int> list(1, i);
                hash.emplace(str, list);
            } else
                iter->second.emplace_back(i);
        }
        vector<vector<string>> ret(hash.size());
        int index = 0;
        for (auto& iter: hash) {
            ret[index].resize(iter.second.size());
            for (int i = 0; i < iter.second.size(); ++i)
                ret[index][i] = strs[iter.second[i]];
            index++;
        }
        return ret;
    }
};
