// step 1: clarify
//
// step 2: solutions
//
// 1. first hashing the array to calculate the count of each unique element
//  time complexity: O(n)
//  space complexity: O(n)
// 2. find the top k elements
//  sort the elements then get the top K
//      time complexity: O(n * logn)
//      space complexity: O(1)
//  put all the elements into the priority queue, which has the size K
//      time complexity: O(n * logk)
//      space complexity: O(k)
//  use quick sort the find the top k elements
//      time complexity: O(n)
//      space complexity: O(1)
//
// step 3: coding
//
// step 4: testing

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (auto n: nums) {
            auto iter = hash.find(n);
            if (iter == hash.end())
                hash.emplace(n, 1);
            else
                iter->second++;
        }
        vector<pair<int, int>> counts(hash.size());
        int index = 0;
        for (auto& iter: hash)
            counts[index++] = pair<int, int>(iter.second, iter.first);
        srand(time(nullptr));
        topK(counts, 0, counts.size() - 1, k);
        vector<int> ret(k);
        for (int i = 0; i < k; ++i)
            ret[i] = counts[i].second;
        return ret;
    }

private:
    void topK(vector<pair<int, int>>& counts, int left, int right, int k) {
        int pivot = rand() % (right - left + 1) + left;
        swap(counts[pivot], counts[left]);
        int low = left;
        int id = right;
        while (id > low) {
            if (counts[id] >= counts[left])
                swap(counts[++low], counts[id]);
            else
                id--;
        }
        swap(counts[low], counts[left]);
        int n = low - left + 1;
        if (k > n)
            topK(counts, low + 1, right, k - n);
        else if (k < n)
            topK(counts, left, low - 1, k);
    }
};
