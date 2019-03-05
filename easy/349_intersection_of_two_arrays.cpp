#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> sets;
        for (auto n: nums1)
            sets.emplace(n);
        vector<int> result;
        for (auto n: nums2)
            if (sets.find(n) != sets.end()) {
                result.emplace_back(n);
                sets.erase(n);
            }
        return result;
    }
};
