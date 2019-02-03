#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty())
            return;
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
            swap(s[i], s[j]);
    }
};
