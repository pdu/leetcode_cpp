// step 1: clarify
//
// step 2: solutions
//
// 1. solve from billion, million, thousand, handred, ten, one
// 2. key thing is to write the code elegant
// 3. if the number is zero, output zero
//
// step 3: coding
//
// step 4: testing
//
// 0 -> zero

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        for (auto& base: base_)
            if (num >= base.first) {
                int k = num / base.first;
                int t = num % base.first;
                string str = numberToWords(k).append(" ").append(base.second);
                if (t > 0)
                    str.append(" ").append(numberToWords(t));
                return str;
            }
        for (auto& base: tens_)
            if (num >= base.first) {
                int k = num - base.first;
                string str = base.second;
                if (k > 0)
                    str.append(" ").append(numberToWords(k));
                return str;
            }
        return ones_[num];
    }

private:
    const vector<pair<int, string>> base_ = {{1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"}};
    const vector<pair<int, string>> tens_ = {{90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}};
    unordered_map<int, string> ones_ = {{0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}};
};
