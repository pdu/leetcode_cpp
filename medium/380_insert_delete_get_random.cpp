#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash.find(val) != hash.end())
            return false;
        array.emplace_back(val);
        hash[val] = array.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hash.find(val) == hash.end())
            return false;
        int id = hash[val];
        if (id != array.size() - 1) {
            hash[array.back()] = id;
            array[id] = array.back();
        }
        hash.erase(val);
        array.resize(array.size() - 1);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (array.empty())
            return 0;
        return array[rand() % array.size()];
    }

private:
    unordered_map<int, int> hash;   // value is the index in the array
    vector<int> array;
};
