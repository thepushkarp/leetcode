class LRUCache {
public:
    int cSize;
    vector<int> order;
    map<int, int> m;
    LRUCache(int capacity) {
        cSize = capacity;
    }

    int get(int key) {
        auto it  = find(order.begin(), order.end(), key);
        if (it == order.end())
            return -1;
        else {
            rotate(it, it+1, order.end());
            return m[key];
        }
    }

    void put(int key, int value) {
        auto it  = find(order.begin(), order.end(), key);
        if (it != order.end()){
            rotate(it, it+1, order.end());
            m[key] = value;
        }
        else {
            m[key] = value;
            order.push_back(key);
        }
        if (order.size() > cSize) {
            m.erase(order[0]);
            order.erase(order.begin());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
