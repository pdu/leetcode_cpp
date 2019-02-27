#include <vector>

using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    NestedIterator(const vector<NestedInteger> &nestedList): nested(nestedList), id(0), iter(nullptr) {
        
    }

    ~NestedIterator() {
        if (iter != nullptr)
            delete iter;
    }

    int next() {
        if (iter != nullptr) {
            if (iter->hasNext())
                return iter->next();
            delete iter;
            iter = nullptr;
            id++;
            return next();
        }
        if (id == nested.size())
            return -1;
        if (nested[id].isInteger())
            return nested[id++].getInteger();
        iter = new NestedIterator(nested[id].getList());
        return next();
    }

    bool hasNext() {
        if (iter != nullptr) {
            if (iter->hasNext())
                return true;
            delete iter;
            iter = nullptr;
            id++;
            return hasNext();
        }
        if (id == nested.size())
            return false;
        if (nested[id].isInteger())
            return true;
        iter = new NestedIterator(nested[id].getList());
        return hasNext();
    }

private:
    vector<NestedInteger> nested;
    int id;
    NestedIterator* iter;
};
