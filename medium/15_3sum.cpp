// step 1: clarify
//
// unique triplets
//
// step 2: solutions
//
// use hash_map to store the value of a, and for loop b and c to find the sum = a + b + c = 0
// in order to remove the duplicates, we store the results in a set
// time complexity: O(n^2)
// space complexity: O(n + m), m is the number of results, the worst case m = n^3 if all the array are zero
//
// sort the array: [-4, -1, -1, 0, 1, 2]
// 1. for loop the number a
// 2. for loop the number b from the next index of a, and for loop the number c from the last index of array
// 3. if a + b + c > 0, c should move forward; else b should move backward
// 4. during the process, a, b and c can skip the same value to avoid the duplicates
//
// step 3: coding
//
// step 4: testing

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3)
            return ret;
        sort(nums.begin(), nums.end());
        for (int a = 0; a < nums.size() - 2; ++a) {
            if (nums[a] + nums[a + 1] + nums[a + 2] > 0)
                break;
            if (nums[a] + nums[nums.size() - 2] + nums[nums.size() - 1] < 0)
                continue;
            // skip the same value of a
            if (a > 0 && nums[a] == nums[a - 1])
                continue;
            int b = a + 1;
            int c = nums.size() - 1;
            while (b < c) {
                if (nums[a] + nums[b] > 0)
                    break;
                int sum = nums[a] + nums[b] + nums[c];
                if (sum > 0)
                    c--;
                else if (sum < 0)
                    b++;
                else {
                    ret.emplace_back(vector<int>({nums[a], nums[b], nums[c]}));
                    // skip the same value of b
                    do b++; while (b < c && nums[b] == nums[b - 1]);
                    // skip the same value of c
                    do c--; while (b < c && nums[c] == nums[c + 1]);
                }
            }
        }
        return ret;
    }
};
