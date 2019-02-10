// step 1: clarify
//
// step 2: solution
//
// 1. find the digits can be used
// 2. dfs all the times
// 3. check the time is valid, and choose the smallest one which is larger than the input
//
// step 3: coding
//
// step 4: testing

#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    string nextTime(const string& currTime) {
        chars.clear();
        for (int i = 0; i < 5; ++i)
            if (i != 2)
                chars.emplace(currTime[i]);
        string ret;
        string buff;
        dfs(currTime, 0, ret, buff);
        return ret;
    }

private:
    void dfs(const string& currTime, int id, string& ret, string& buff) {
        if (id == 5) {
            if (buff == currTime ||!isValid(buff))
                return;
            if (ret.empty() 
                    || (ret > currTime && buff > currTime && buff < ret) 
                    || (ret < currTime && (buff < ret || buff > currTime))) {
                ret = buff;
                return;
            }
            return;
        }
        if (id == 2) {
            buff.push_back(':');
            dfs(currTime, id + 1, ret, buff);
            buff.pop_back();
            return;
        }
        for (auto iter: chars) {
            buff.push_back(iter);
            dfs(currTime, id + 1, ret, buff);
            buff.pop_back();
        }
    }

    bool isValid(const string& buff) {
        string hour = buff.substr(0, 2);
        string minute = buff.substr(3, 2);
        return hour >= "00" && hour <= "23" && minute >= "00" && minute <= "59";
    }

    unordered_set<char> chars;
};

int main() {
    Solution sln;
    cout << "19:34 -> " << sln.nextTime("19:34") << endl;
    cout << "23:59 -> " << sln.nextTime("23:59") << endl;
    return 0;
}
