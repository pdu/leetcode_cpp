// step 1: clarify
//
// empty string is valid
//
// step 2: solutions
//
// the naive solution is: 
//  just for loop the string, if find the adjacent paired parentheses, delete them; 
//  then for loop again until nothing can be deleted
//  it's valid if the string is empty at last, or else it's invalid
// time complexity: O(n^2)
// space complexity: O(1)
//
// based on the naive solution, after the paired parentheses are deleted, just keep looping the following string
// it's quite like the stack operations:
//  1. first in last out
//  2. only check the top element
// time complexity: O(n), because every element only push to and pop from stack once
// space complexity: O(n), the space of the stack
//
// step 3: coding
//
// step 4: testing
//
//  "" true
//  ()[]{} true
//  [{()}] true
//  []{}} false
//  ([]() false
//  ()([]{} false
//  (}{) false

#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(const string& s) {
        stack<char> data;
        for (auto c: s) {
            auto it = pairs_.find(c);
            if (it == pairs_.end())
                data.push(c);
            else if (!data.empty() && it->second == data.top())
                data.pop();
            else
                return false;
        }
        return data.empty();
    }

private:
    unordered_map<char, char> pairs_ = {{')', '('}, {'}', '{'}, {']', '['}};
};
