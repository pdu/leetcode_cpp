// step 1: clarify
//
// step 2: solutions
//
// 1. move the nums1 elements backward for n positions
// 2. merge two arrays
//
// step 3: coding
//
// step 4: testing

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m - 1; i >= 0; --i)
            nums1[i + n] = nums1[i];
        int id1 = 0;
        int id2 = 0;
        int id = 0;
        while (id1 < m && id2 < n) {
            if (nums1[id1 + n] < nums2[id2])
                nums1[id++] = nums1[n + id1++];
            else
                nums1[id++] = nums2[id2++];
        }
        for (; id1 < m; ++id1)
            nums1[id++] = nums1[n + id1];
        for (; id2 < n; ++id2)
            nums1[id++] = nums2[id2];
    }
};
