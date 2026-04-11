class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq_;
    int k_;
public:
    KthLargest(int k, vector<int>& nums):k_(k) {
        for(auto num:nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if(pq_.size() < k_) {
            pq_.push(val);
        } else if(pq_.top() < val) {
            pq_.pop();
            pq_.push(val);
        }
        return pq_.top();
    }
};

/**f
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */