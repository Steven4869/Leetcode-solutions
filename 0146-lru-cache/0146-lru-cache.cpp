class LRUCache {
public:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>>cache;
    list<int>lruList;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        
        lruList.splice(lruList.begin(), lruList, cache[key].second);
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            cache[key].first = value;
            lruList.splice(lruList.begin(), lruList, cache[key].second);
            return;
        }
        if(cache.size() == capacity){
            int evictKey = lruList.back();
            lruList.pop_back();
            cache.erase(evictKey);
        }
        lruList.push_front(key);
        cache[key]={value, lruList.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */