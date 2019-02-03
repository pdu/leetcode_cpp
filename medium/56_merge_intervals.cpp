// step 1: clarify
//
// step 2: solutions
//
// 1. sort the array by x
// 2. for loop the array to find the intersection
//
// step 3: coding
//
// step 4: testing

#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool operator< (const Interval& a, const Interval& b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if (intervals.empty())
            return ret;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0].start;
        int end = intervals[0].end;
        for (auto& interval: intervals) {
            if (interval.start <= end)
                end = max(end, interval.end);
            else {
                ret.emplace_back(start, end);
                start = interval.start;
                end = interval.end;
            }
        }
        ret.emplace_back(start, end);
        return ret;
    }
};
