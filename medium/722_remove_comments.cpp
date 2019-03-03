// string processing
//
// state 1: in code
// state 2: in line comments
// state 3: in blocking comments
//
// not a test case: "string s = "/* Not a comment. */";"
// but maybe a follow up question in the interview

#include <string>
#include <vector>

using namespace std;

enum CodeState {
    CODE,
    BLOCK_COMMENTS
};

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> result;
        CodeState state = CODE;
        string buff;
        for (auto& line: source) {
            for (int i = 0; i < line.size(); ++i) {
                switch (state) {
                    case CODE:
                        if (line[i] == '/' && i + 1 < line.size() && line[i + 1] == '*') {
                            state = BLOCK_COMMENTS;
                            i++;
                        } else if (line[i] == '/' && i + 1 < line.size() && line[i + 1] == '/')
                            i = line.size();
                        else
                            buff.push_back(line[i]);
                        break;
                    case BLOCK_COMMENTS:
                        if (line[i] == '*' && i + 1 < line.size() && line[i + 1] == '/') {
                            state = CODE;
                            i++;
                        }
                        break;
                }
            }
            if (!buff.empty() && state == CODE) {
                result.emplace_back(buff);
                buff.clear();
            }
        }
        return result;
    }
};
