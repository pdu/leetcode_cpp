// disjoint set

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        for (auto n: nums) {
            if (hash.find(n) != hash.end())
                continue;
            int count = 1;
            pair<int, int> lower = get(n - 1);
            if (lower.second > 0) {
                count += lower.second;
                hash[lower.first] = pair<int, int>(n, 1);
            }
            pair<int, int> higher = get(n + 1);
            if (higher.second > 0) {
                count += higher.second;
                hash[higher.first] = pair<int, int>(n, 1);
            }
            hash[n] = pair<int, int>(n, count);
            ret = max(ret, count);
        }
        return ret;
    }

private:
    pair<int, int> get(int n) {
        auto it = hash.find(n);
        if (it == hash.end())
            return pair<int, int>(0, 0);
        if (it->second.first == n)
            return it->second;
        return get(it->second.first);
    }

    unordered_map<int, pair<int, int>> hash; // pair first: value second: count
};
