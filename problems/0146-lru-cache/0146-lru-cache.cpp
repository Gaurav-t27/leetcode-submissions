class LRUCache {
    int cap_;
    list<pair<int,int>> cache_;
    using lpit = list<pair<int, int>>::iterator;
    unordered_map<int, lpit> hm_;
public:
    LRUCache(int capacity) {
        cap_ = capacity;
    }
    
    int get(int key) {
        if(hm_.find(key) == hm_.end()) {
            return -1;
        }
        cache_.splice(cache_.begin(),cache_,hm_[key]);
        return hm_[key]->second;
    }
    
    void put(int key, int value) {
        if(hm_.find(key)!=hm_.end()) {
            hm_[key]->second = value;
            cache_.splice(cache_.begin(), cache_, hm_[key]);
        } else {
            if(cache_.size() == cap_) {
                int lastKey = cache_.back().first;
                hm_.erase(lastKey);
                cache_.pop_back();
            }
            cache_.push_front({key, value});
            hm_[key] = cache_.begin();
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */