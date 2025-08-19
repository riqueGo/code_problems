package lru_cache;

import java.util.HashMap;

class LRUCache {
    private class CacheNode {
        int key, val;
        CacheNode prev, next;

        CacheNode(int key, int val) {
            this.key = key;
            this.val = val;
        }
    }

    private int capacity;
    private HashMap<Integer, CacheNode> cache;
    private CacheNode head, tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.cache = new HashMap<>();

        // Dummy head and tail
        head = new CacheNode(-1, -1);
        tail = new CacheNode(-1, -1);
        head.next = tail;
        tail.prev = head;
    }

    private void insert(CacheNode node) {
        // Insert right after head
        CacheNode next = head.next;
        head.next = node;
        node.prev = head;
        node.next = next;
        next.prev = node;
    }

    private void remove(CacheNode node) {
        CacheNode prev = node.prev;
        CacheNode next = node.next;
        prev.next = next;
        next.prev = prev;
    }

    public int get(int key) {
        if (!cache.containsKey(key)) return -1;

        CacheNode node = cache.get(key);
        remove(node);
        insert(node);
        return node.val;
    }

    public void put(int key, int value) {
        CacheNode node;
        if (cache.containsKey(key)) {
            node = cache.get(key);
            node.val = value;
            remove(node);
        } else {
            node = new CacheNode(key, value);
            cache.put(key, node);
        }

        insert(node);

        if (cache.size() > capacity) {
            CacheNode toDelete = tail.prev;
            remove(toDelete);
            cache.remove(toDelete.key);
        }
    }
}
