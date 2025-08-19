/*
Time Complexity:
    - get(key): O(1)
        Lookup in unordered_map + remove + insert (constant-time pointer operations)
    - put(key, value): O(1)
        Lookup + insert/update in unordered_map + remove/insert (O(1))
        Possible deletion of least recently used node (O(1))
    => Both operations are O(1) on average

Space Complexity:
    - Doubly linked list with at most `capacity` nodes → O(capacity)
    - Hash map storing key -> node mapping for at most `capacity` entries → O(capacity)
    - Total: O(capacity)
*/

#include <unordered_map>

using std::unordered_map;

class CacheNode {
public:
    CacheNode* next;
    CacheNode* prev;
    int key;
    int val;

    CacheNode(int _key, int _val) : next(nullptr), prev(nullptr), key(_key), val(_val) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, CacheNode*> cache;
    CacheNode* head;
    CacheNode* tail;

    void insert(CacheNode* node) {
        CacheNode* next = head->next;
        next->prev = node;
        head->next = node;

        node->next = next;
        node->prev = head;
    }

    void remove(CacheNode* node) {
        CacheNode* next = node->next;
        CacheNode* prev = node->prev;

        next->prev = prev;
        prev->next = next;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new CacheNode(-1, -1);
        this->tail = new CacheNode(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;

        CacheNode* node = cache[key];
        remove(node);
        insert(node);

        return node->val;
    }
    
    void put(int key, int value) {
        CacheNode* node;
        if(cache.find(key) == cache.end()) {
            node = new CacheNode(key, value);
            cache[key] = node;
        } else {
            node = cache[key];
            node->val = value;
            remove(node);
        }

        insert(node);

        if(cache.size() > capacity) {
            CacheNode* toDelete = tail->prev;
            remove(toDelete);
            cache.erase(toDelete->key);
            delete toDelete;
        }
    }

    ~LRUCache() {
        CacheNode* curr = head;
        while (curr != nullptr) {
            CacheNode* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 int main() {
    LRUCache* cache = new LRUCache(2);
    cache->put(2, 1);
    cache->put(2, 2);
    int val1 = cache->get(2);
    cache->put(1, 1);
    cache->put(4, 1);
    int val2 = cache->get(2);

    delete cache;
    return 0;
}