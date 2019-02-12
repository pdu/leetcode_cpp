// step 1: clarify
//
// step 2: solution
//
// 1. has an increase sequence
// 2. transfer int into string
// 
// string has 62 chars, a-z, A-Z, 0-9

#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string ret(7, ' ');
        int v = count++;
        for (int i = 0; i < 7; ++i) {
            ret[i] = getchar(v % 62);
            v /= 62;
        }
        hash[ret] = longUrl;
        return ret;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return hash[shortUrl];
    }

private:
    inline char getchar(int v) {
        if (v < 26)
            return 'a' + v;
        else if (v < 52)
            return 'A' + v - 26;
        else
            return '0' + v - 52;
    }

    unordered_map<string, string> hash;
    int count;
};
