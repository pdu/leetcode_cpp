// step 1: clarify
//
// 1. it's two sorted array
// 2. if there're two medium numbers, get the average value
// 3. the arrays cannot be both empty but maybe empty
//
// step 2: solutions
//
// the problem is: find the kth number in two sorted array 
//
// the first solution:
// 1. get 2 indexes starting from the beginnings of the two arrays: i1 = 0, i2 = 0
// 2. loop forward: if num1[i1] <= num2[i2]: i1++ else: i2++
// 3. so as to find the medium numbers
// time complexity: O(m + n)
// space complexity: O(1)
//
// the second solution:
// 1. binary search the target in the range of min(num1, num2) to max(num1, num2)
// 2. then binary search in num1 and num2 to checkout how many numbers are smaller the target
// 3. so as to find the kth number, k = (m+n+1)/2 or (m+n+1)/2+1
// time complexity: O(log(INT_MAX) * log(m * n))
// space complexity: O(1)
//
// the third solution:
// 1. binary search num1 and num2 together, to find the kth number
// 2. so the situation is like the following:
//      num1: ---t1---|---t2---
//      num2: ---t3---|---t4---
//      t1, t2, t3, t4 is the length of each part
//    in the case of num1[mid] <= num2[mid]:
//      if k <= t1: search kth number in t1 + t3
//      else if k <= t1 + t3: search kth number in t1 + t2 + t3
//      else: search (k-t1)th number in t2 + t3 + t4
// 3. the terminate case is any of the arrays is empty or both of the arrays are size 1
// time complexity: O(log(m + n))
// space complexity: O(1)
// it's more convenient to implement in c using pointer

#include <vector>

using namespace std;

// solution 2
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty())
            return median(nums2);
        else if (nums2.empty())
            return median(nums1);
        int total_num = nums1.size() + nums2.size();
        if (total_num % 2 == 1)
            return kthNumber(nums1, nums2, total_num / 2 + 1);
        else
            return (kthNumber(nums1, nums2, total_num / 2) + kthNumber(nums1, nums2, total_num / 2 + 1)) / 2.0;
    }

private:
    double median(vector<int>& nums) {
        int n = nums.size();
        if (n % 2 == 0)
            return (nums[n / 2] + nums[n / 2 - 1]) / 2.0;
        else
            return nums[n / 2];
    }

    int kthNumber(vector<int>& nums1, vector<int>& nums2, int kth) {
        int left = min(nums1[0], nums2[0]);
        int right = max(nums1.back(), nums2.back());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int index = lowerBound(nums1, mid) + lowerBound(nums2, mid);
            if (index > kth)
                right = mid - 1;
            else if (index < kth)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    int lowerBound(vector<int>& num, int target) {
        int left = 0;
        int right = num.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target >= num[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};

// solution 3

double median(int* nums, int numsSize) {
    if (numsSize % 2 == 0)
        return (nums[numsSize / 2] + nums[numsSize / 2 - 1]) / 2.0;
    else
        return nums[numsSize / 2];
}

void swap2(int **nums1, int **nums2) {
    int* tmp = *nums1;
    *nums1 = *nums2;
    *nums2 = tmp;
}

void swap(int *num1, int *num2) {
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int kthNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    if (nums1Size == 0)
        return nums2[k - 1];
    else if (nums2Size == 0)
        return nums1[k - 1];
    else if (nums1Size == 1 && nums2Size == 1)
        return k == 1 ? min(nums1[0], nums2[0]) : max(nums1[0], nums2[0]);
    int nums1Left = (nums1Size + 1) / 2;
    int nums1Right = nums1Size - nums1Left;
    int nums2Left = (nums2Size + 1) / 2;
    int nums2Right = nums2Size - nums2Left;
    if (nums1[nums1Left - 1] > nums2[nums2Left - 1]) {
        swap2(&nums1, &nums2);
        swap(&nums1Size, &nums2Size);
        swap(&nums1Left, &nums2Left);
        swap(&nums1Right, &nums2Right);
    }
    // should be care that every recursive should decrease the array size
    if (k <= nums1Left)
        return kthNumber(nums1, nums1Left, nums2, nums2Left, k);
    else if (k <= nums1Left + nums2Left) {
        if (nums2Left == 1)
            return kthNumber(nums1 + nums1Left, nums1Right, nums2, nums2Left, k - nums1Left);
        else
            return kthNumber(nums1, nums1Size, nums2, nums2Left, k);
    }
    else
        return kthNumber(nums1 + nums1Left, nums1Right, nums2, nums2Size, k - nums1Left);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size == 0)
        return median(nums2, nums2Size);
    else if (nums2Size == 0)
        return median(nums1, nums1Size);
    int total = nums1Size + nums2Size;
    if (total % 2 == 0)
        return (kthNumber(nums1, nums1Size, nums2, nums2Size, total / 2) + kthNumber(nums1, nums1Size, nums2, nums2Size, total / 2 + 1)) / 2.0;
    else
        return kthNumber(nums1, nums1Size, nums2, nums2Size, total / 2 + 1);
}
