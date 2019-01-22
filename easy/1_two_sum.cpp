// step 1: clarify
//
// Q: would the operation overflow int32?
// A: no
//
// Q: other restrictions?
// A: has exactly one solution, cannot use the same elements twice
//
// step 2: solutions
//
// naive solution to for loop twice of the array to find the target, like:
//  for n1 in nums:
//      for n2 in nums:
//          if n1 + n2 is target:
//              return
// time complexity: O(n*n)
// space complexity: O(1)
//
// faster solution to store the array in hash table, and find the value of target - n in the hash table
//  for n in nums:
//      if hash_table contains target-n:
//          return
//      insert n to hash_table
// time complexity: O(n)
// space complexity: O(1)
//
// step 3: coding
//
// step 4: testing

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        unordered_map<int, int> data;   // key: num value: index
        for (int i = 0; i < nums.size(); ++i) {
            auto it = data.find(target - nums[i]);
            if (it != data.end()) {
                result[0] = it->second;
                result[1] = i;
                break;
            }
            data[nums[i]] = i;
        }
        return result;
    }
};
