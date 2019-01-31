// step 1: clarify
//
// 1. do all the operations in O(1) time complexity
// 2. delete the least recent used items when capacity is full
//
// step 2: solutions
//
// 1. get/set in O(1) time complexity, so we need hash table to store the key to value
// 2. maintain the least recent used data structure, can use linked list, ordered by the visit timestamp
// 3. in order to move or delete at any position of the linked list, we should use bidirectional linked list
// 4. in the hash table, we store the key to the position of the node in the linked list so as to find it
//
// step 3: coding
//
// step 4: testing
//
// 1. linked list is empty
// 2. linked list has only one node
// 3. linked list has only two nodes
// 4. add when the capacity is full
//
// step 5: follow up questions
//
// 1. what abou the multi concurrency cases?

#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity), head_(nullptr), tail_(nullptr) {}

    int get(int key) {
        int ret = -1;
        auto it = hash_.find(key);
        if (it != hash_.end()) {
            ret = it->second->value;
            move2head(it->second);
        }
        return ret;
    }

    void put(int key, int value) {
        Node* node = nullptr;
        auto it = hash_.find(key);
        if (it != hash_.end()) {
            node = it->second;
            node->value = value;
        } else if (hash_.size() < capacity_) {
            node = new Node(key, value);
            hash_[key] = node;
        } else {
            node = tail_;
            removetail();
            node->key = key;
            node->value = value;
            hash_[key] = node;
        }
        move2head(node);
    }

private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(): prev(nullptr), next(nullptr) {}
        Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    // 1. tail_ cannot be nullptr
    // 2. remove it from the linkedlist
    // 3. remove it from hash table
    void removetail() {
        hash_.erase(tail_->key);
        if (tail_->prev == nullptr) {
            head_ = nullptr;
            tail_ = nullptr;
        } else {
            Node* prev = tail_->prev;
            tail_->prev = nullptr;
            prev->next = nullptr;
            tail_ = prev;
        }
    }

    // 1. delete this node from linked list
    //    there's a case the node is not in the linked list
    // 2. add it into head
    void move2head(Node* node) {
        if (head_ == nullptr) {
            head_ = tail_ = node;
            return;
        }
        if (node == head_)
            return;
        if (node->prev != nullptr)
            node->prev->next = node->next;
        if (node->next != nullptr)
            node->next->prev = node->prev;
        if (node == tail_)
            tail_ = node->prev;
        node->prev = nullptr;
        node->next = head_;
        head_->prev = node;
        head_ = node;
    }

    int capacity_;
    Node* head_;
    Node* tail_;    // delete from the tail
    unordered_map<int, Node*> hash_;
};
