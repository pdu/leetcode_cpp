// step 1: clarify
//
// 1. n is at least 2
// 2. area = (j - i) * min(a[i], a[j])
//
// step 2: solutions
//
// the naive solution is to nested for loop
//  for i = 0; i < n; ++i:
//      for j = i + 1; j < n; ++j:
//          area = max(area, (j - i) * min(a[i]. a[j]))
// time complexity: O(n^2)
// space complexity: O(1)
//
// based on the naive solution, do some optimisation is:
//  for k in range(i, j):
//      if a[k] <= a[j] or a[k] <= a[i]:
//          area(i, k) <= area(i, j)
//          area(k, j) <= area(i, j)
// so we can set to pointers:
//  1. i = 0, j = n - 1, calculate the area
//  2. move i forward to a larger value if a[i] < a[j]
//     or move j backward to a larger value if a[i] > a[j]
// time complexity: O(n)
// space complexity: O(1)
//
// step 3: coding
//
// step 4: testing

#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            area = max(area, (right - left) * min(height[left], height[right]));
            if (height[left] <= height[right])
                left++;
            else
                right--;
        }
        return area;
    }
};
