class MyHashSet {
    vector<vector<int>> buff_;
    int capacity_;

    int getHash(int key) {
        return key & (capacity_-1);
    }
public:
    MyHashSet() :capacity_(1024*128) {
        buff_.resize(capacity_);
    }
    
    void add(int key) {
        if(contains(key)) return;
        int idx = getHash(key);

        buff_[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = getHash(key);

        buff_[idx].erase(std::remove(buff_[idx].begin(),buff_[idx].end(),key),buff_[idx].end());
    }
    
    bool contains(int key) {
        int idx = getHash(key);

        return find(buff_[idx].begin(),buff_[idx].end(), key) != buff_[idx].end();

    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */