#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        if (numbers.empty())
            return result;
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                result.emplace_back(left + 1);
                result.emplace_back(right + 1);
                break;
            } else if (sum < target)
                left++;
            else
                right--;
        }
        return result;
    }
};
