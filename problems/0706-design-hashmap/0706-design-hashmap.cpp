class MyHashMap {
    vector<list<pair<int,int>>> bucket_;
    size_t capacity_;
    int getHash(int key) const {
        return key & (capacity_-1);
    }
public:
    MyHashMap():capacity_(16384) {
        bucket_.resize(capacity_);
    }
    
    void put(int key, int value) {
        int idx = getHash(key);

        for(auto& p: bucket_[idx]) {
            if(p.first == key) {
                p.second = value;
                return;
            }
        }
        bucket_[idx].push_back({key,value});
    }
    
    int get(int key) {
        int idx = getHash(key);

        for(const auto& p: bucket_[idx]) {
            if(p.first == key) {
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = getHash(key);
        bucket_[idx].remove_if([key](const auto& p) { return p.first == key;});
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */