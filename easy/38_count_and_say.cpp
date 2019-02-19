#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        while (--n) {
            string buff;
            int num = 1;
            for (int i = 1; i < ret.size(); ++i) {
                if (ret[i] == ret[i - 1])
                    num++;
                else {
                    append(buff, num);
                    buff.push_back(ret[i - 1]);
                    num = 1;
                }
            }
            append(buff, num);
            buff.push_back(ret.back());
            ret = buff;
        }
        return ret;
    }

private:
    void append(string& buff, int n) {
        string tmp;
        while (n) {
            tmp.push_back(n%10 + '0');
            n /= 10;
        }
        for (int i = tmp.size() - 1; i >= 0; --i)
            buff.push_back(tmp[i]);
    }
};
