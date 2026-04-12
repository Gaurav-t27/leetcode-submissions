class MyHashSet {
    size_t table_size;
    std::vector<std::vector<int>> table;

    int hashFunction(int key) {
        return key % table_size;
    }    
public:
    MyHashSet() :table_size(10000){
        table.resize(table_size);
    }
    
    void add(int key) {
        int idx = hashFunction(key);
        
        if (std::find(table[idx].begin(), table[idx].end(), key) == table[idx].end()) {
            table[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx = hashFunction(key);

        auto & bucket = table[idx];
        auto it = std::find(bucket.begin(),bucket.end(),key);
        if(it != bucket.end()) {
            *it = bucket.back();
            bucket.pop_back();
        }
    }
    
    bool contains(int key) {
        int idx = hashFunction(key);
        auto& bucket = table[idx];
        return std::find(bucket.begin(),bucket.end(),key) != bucket.end();

    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */