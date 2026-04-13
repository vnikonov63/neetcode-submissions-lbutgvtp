class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        cache.clear();
        lru_d = new Node(0, 0);
        mru_d = new Node(0, 0);
        lru_d->next = mru_d;
        lru_d->prev = nullptr; /* for clarity */
        mru_d->next = nullptr; /* for clarity */
        mru_d->prev = lru_d; 
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);

            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end())
            remove(cache[key]);
        
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > capacity) {
            Node* lru = lru_d->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* lru_d;
    Node* mru_d;

    void remove(Node* node) {
        Node* prev = node->prev; /* Finding the previous */
        Node* next = node->next; /* Finding the next one */
        prev->next = next; /* Updating the previous */
        next->prev = prev; /* Updating the next one */
    }

    void insert(Node* node) {
        Node* prev = mru_d->prev; /* Finding the current Most Recently Used Node */
        prev->next = node; /* The current one should become the next of the previously Most Recently Used */
        node->prev = prev; /* A reverse step of above to preserve integrity of doubly linked list */
        node->next = mru_d; /* And we connect the current node to the mru dummy */
        mru_d->prev = node; /* A reverse step of above to preserve integrity of doubly linked list */
    }
};
