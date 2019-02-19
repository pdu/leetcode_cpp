// dynamic programming
// O(n^2)

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> hash;
        for (int i = 1; i < stones.size(); ++i)
            hash[stones[i]] = unordered_set<int>();
        hash[stones[0]] = unordered_set<int>({0});
        for (int i = 0; i < stones.size() - 1; ++i) {
            unordered_set<int>& speeds = hash[stones[i]];
            for (auto speed: speeds) {
                for (int d = -1; d <= 1; ++d) {
                    int next_speed = speed + d;
                    if (next_speed <= 0)
                        continue;
                    if (stones[i] + next_speed == stones.back())
                        return true;
                    auto it = hash.find(stones[i] + next_speed);
                    if (it == hash.end())
                        continue;
                    it->second.emplace(next_speed);
                }
            }
        }
        return false;
    }
};
