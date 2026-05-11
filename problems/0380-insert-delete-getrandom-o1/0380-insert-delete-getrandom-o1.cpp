class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> um;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(um.find(val) != um.end()) return false;
        v.push_back(val);
        um[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(um.find(val) == um.end()) return false;
        int pos = um[val];
        int last = v.back();

        v[pos] = last;
        um[last] = pos;

        v.pop_back();
        um.erase(val);

        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */