// step 1: clarify
//
// 1. there may be duplicate points
//
// step 2: solutions
//
// for loop point-1 and point-2 as the line, point-1 and point-2 should not be duplicated:
//  for loop point-2 to check it's on the same line
// time complexity: O(n^3)
// space complexity: O(1)
//
// for loop point-1 as one point of the line:
//  for loop point-2:
//      adds all the duplicate points
//      adds all the points parallel with the x-ray
//      adds all the points parallel with the y-ray
//      put the line rate into hash table:
//          rate = (y2 - y1) / (x2 - x1), y2 > y1
//          store the pair<(y2 - y1)/gcd, (x2 - x1)/gcd>
// time complexity: O(n^2)
// space complexity: O(n)
//
// step 3: coding
//
// step 4: testing

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct Hasher
{
    std::size_t operator()(const pair<int, int>& k) const
    {
        return k.first + k.second;
    }
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2)
            return points.size();
        int ret = 0;
        for (int i = 0; i < points.size(); ++i) {
            int same = 0;
            int x_ray = 0;
            int y_ray = 0;
            int max_rate = 0;
            unordered_map<pair<int, int>, int, Hasher> hash;
            for (int j = 0; j < points.size(); ++j) {
                if (i == j)
                    continue;
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    same++;
                    continue;
                }
                if (points[i].x == points[j].x) {
                    y_ray++;
                    continue;
                }
                if (points[i].y == points[j].y) {
                    x_ray++;
                    continue;
                }
                pair<int, int> rate = getRate(points[i], points[j]);
                auto iter = hash.find(rate);
                if (iter == hash.end()) {
                    hash.emplace(rate, 1);
                    max_rate = ::max(max_rate, 1);
                } else {
                    iter->second++;
                    max_rate = ::max(max_rate, iter->second);
                }
            }
            ret = ::max(ret, same + 1 + max(x_ray, y_ray, max_rate));
        }
        return ret;
    }

private:
    inline int max(int a, int b, int c) {
        return ::max(a, ::max(b, c));
    }

    inline pair<int, int> getRate(const Point& a, const Point& b) {
        int y = a.y - b.y;
        int x = a.x - b.x;
        int g = gcd(y, x);
        return pair<int, int>(y/g, x/g);
    }
};
