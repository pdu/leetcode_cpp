// step 1: clarify
//
// step 2: solutions
//
// 1. parsing the string T into a hash table: char -> int, record the counts of each char
// 2. use two pointer in string S, initially start = end = 0, initially matched count: matched = 0
// 3. if S[start, end] do not contains T, move end forward:
//  add the count of s[end]
//  if count of s[end] == the count in T, matched++
//  if matched == hash.size(), it means s[start, end] contains T, then find the minimum result
// 4. if S[start, end] contains T, move start forward:
//  minus the count of s[start - 1]
//  if count of s[start - 1] == the count in T -1, matched--
// time complexity: O(n)
// space complexity: O(n)
//
// step 3: coding
//
// step 4: testing

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(const string& s, const string& t) {
        if (t.empty())
            return "";
        unordered_map<char ,int> base;
        for (auto c: t) {
            auto iter = base.find(c);
            if (iter == base.end())
                base.emplace(c, 1);
            else
                iter->second++;
        }
        unordered_map<char ,int> count;
        int min_len = 0;
        int min_start = 0;
        int matched = 0;
        int start = 0;
        int end = -1;
        while (true) {
            if (matched < base.size()) {
                end++;
                if (end >= s.length())
                    break;
                auto iter = base.find(s[end]);
                if (iter == base.end())
                    continue;
                int num = updateCount(count, s[end], 1);
                if (num == iter->second)
                    matched++;
            } else {
                start++;
                auto iter = base.find(s[start - 1]);
                if (iter != base.end()) {
                    int num = updateCount(count, s[start - 1], -1);
                    if (num == iter->second - 1)
                        matched--;
                }
            }
            if (matched < base.size())
                continue;
            int len = end - start + 1;
            if (min_len == 0 || min_len > len) {
                min_len = len;
                min_start = start;
            }
        }
        return min_len == 0 ? "" : s.substr(min_start, min_len);
    }

private:
    int updateCount(unordered_map<char, int>& count, char c, int num) {
        auto iter = count.find(c);
        if (iter == count.end()) 
            return count[c] = num;
        else
            return iter->second += num;
    }
};
