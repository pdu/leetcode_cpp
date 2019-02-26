// use one maximum priority queue and one minimum priority queue
// the maximum priority queue stores the smaller 50% of the elements
// the minimum priority queue stores the larger 50% of the elements

#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // max_queue is empty
        if (max_queue.empty()) {
            max_queue.emplace(num);
            return;
        }
        // num is less than the top value of max_queue
        if (num < max_queue.top()) {
            max_queue.emplace(num);
            if (max_queue.size() - min_queue.size() > 1) {
                min_queue.emplace(max_queue.top());
                max_queue.pop();
            }
        } else {
            min_queue.emplace(num);
            if (min_queue.size() > max_queue.size()) {
                max_queue.emplace(min_queue.top());
                min_queue.pop();
            }
        }
    }
    
    double findMedian() {
        if (max_queue.size() == min_queue.size())
            return (max_queue.top() + min_queue.top()) / 2.0;
        else
            return max_queue.top();
    }

private:
    priority_queue<int, vector<int>, less<int>> max_queue;
    priority_queue<int, vector<int>, greater<int>> min_queue;
};
