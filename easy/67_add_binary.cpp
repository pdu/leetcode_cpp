#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int carry = 0;
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; --i, --j) {
            int na = i >= 0 ? a[i] - '0' : 0;
            int nb = j >= 0 ? b[j] - '0' : 0;
            ret.push_back('0' + (na ^ nb ^ carry));
            carry = (na + nb + carry) >> 1;
        }
        if (carry != 0)
            ret.push_back('0' + carry);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
