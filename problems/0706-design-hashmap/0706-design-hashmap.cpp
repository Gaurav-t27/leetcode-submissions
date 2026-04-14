class MyHashMap {
    vector<list<pair<int,int>>> bucket_;
    size_t size_;
    int getHash(int key) const {
        return key % size_;
    }
public:
    MyHashMap():size_(1031) {
        bucket_.resize(size_);
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
        for(auto it = bucket_[idx].begin();it != bucket_[idx].end(); it++) {
            if(it->first == key) {
                bucket_[idx].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */