class LRUCache {
public:
    //Fixed size or the capacity
    int capacity;
    //Making up the map for the access of the items
    unordered_map<int, pair<int, list<int>::iterator>>cache;
    //Making the Doubly Linked List for keeping the track
    list<int>lrulist;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        //If the element is not in the map then return -1
        if(cache.find(key) == cache.end())
            return -1;
        //When the item is accessed it is moved to the head of DLL 
        //to indicate the Most Recently Used operation
        lrulist.splice(lrulist.begin(), lrulist, cache[key].second);
        return cache[key].first;
    }
    
    void put(int key, int value) {
        //If the cache is not full then new item is added to DLL 
        //into the hashmap
        if(cache.find(key)!=cache.end()){
            cache[key].first = value;
            lrulist.splice(lrulist.begin(), lrulist, cache[key].second);
            //Update the iterator
            cache[key].second = lrulist.begin();
            return;
        }
        //If the cache is full 
        if(cache.size() == capacity){
            //The last element in the list is removed
            int evictKey = lrulist.back();
            lrulist.pop_back();
            //Erase it from the map
            cache.erase(evictKey);
        }
        lrulist.push_front(key);
        cache[key]={value, lrulist.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */