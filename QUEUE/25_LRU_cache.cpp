LINK:https://www.youtube.com/watch?v=xDEuM5qa0zg


Design a data structure for LRU Cache
Difficulty Level : Medium
Last Updated : 05 Jul, 2021
Design a data structure for LRU Cache. It should support the following operations: get and set.

get(key) – Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) – Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Examples:

// Let’s say we have a LRU cache of capacity 2. 
LRUCache cache = new LRUCache(2);
cache.set(1, 10); // it will store a key (1) with value 10 in the cache. 
cache.set(2, 20); // it will store a key (2) with value 20 in the cache. 
cache.get(1); // returns 10 
cache.set(3, 30); // evicts key 2 and store a key (3) with value 30 in the cache. 
cache.get(2); // returns -1 (not found) 
cache.set(4, 40); // evicts key 1 and store a key (4) with value 40 in the cache. 
cache.get(1); // returns -1 (not found) 
cache.get(3); // returns 30 
cache.get(4); // returns 40




class LRUCache {
public:
    class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val; 
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int, node*>m;
    
    LRUCache(int capacity) {
        cap = capacity;    
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node* resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res; 
        }
    
        return -1;
    }
    
    void put(int key_, int value) {
        if(m.find(key_) != m.end()) {
            node* existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if(m.size() == cap) {
          m.erase(tail->prev->key);
          deletenode(tail->prev);
        }
        
        addnode(new node(key_, value));
        m[key_] = head->next; 
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */